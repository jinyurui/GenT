CPP
****************

Thread
+++++++++++++
.. code::

    #include <mutex>
    #include <functional>
    #include <condition_variable>
    #include <thread>
    #include <QElapsedTimer>
    #include <QDebug>

    class ThreadAbout
    {
    public:

        struct ThreadInfo{
            ThreadAbout* wrapper;
            void(*body)(void*arg);
            void* arg;
        };

        ThreadAbout(void(*body)(void*arg), void* arg){
            ThreadInfo* info_ = new ThreadInfo;
            info_->wrapper = this;
            info_->arg = arg;
            info_->body = body;
            m_td = std::thread([](void*arg){
                // time test
                QElapsedTimer timer;
                timer.start();

                ThreadInfo info = *static_cast<ThreadInfo*>(arg);
                free(arg);

                qDebug() << "std::thread wiat to ready";

                // wait ready
                std::unique_lock<std::mutex> lock(info.wrapper->m_mutex);
                info.wrapper->m_condition.wait(lock, [info](){ return info.wrapper->m_isReady;});
                lock.unlock();

                qDebug() << "std::thread will run call back";

                qDebug() << "The slow operation took (wait time)" << timer.elapsed() << "milliseconds";

                // run call back
                (*info.body)(info.arg);

            }, info_);
        }


        ~ThreadAbout(){
            join();
        }

        void start(){
            std::lock_guard<std::mutex> lock(m_mutex);
            m_isReady = true;
            m_condition.notify_one();
        }

        void join(){
            if(m_td.joinable()){
                m_td.join();
                qDebug() << "join finish";
            }
        }

    private:
        bool m_isReady = false;
        std::thread m_td;
        std::mutex m_mutex;
        std::condition_variable m_condition;
    };


CRTP(CR template pattern)
++++++++++++++++++++++++++++++
.. code::

    template<typename T>
    class Base{
        void run(){
            static_cast<T*>(this)->tryDo();
        }
    };

    class Super : public Base<Super>{
        void tryDo(){
            // call super with no vtb
        }
    };

VTB
++++++++++++++++++++++++
.. code::

    class __declspec(novtable) Base{
        virtual void one() = 0;
        virtual void two(int a) = 0;
        virtual void two(int a, int b) = 0;
    };

    the order is:
    typedef struct Base Base;
    typedef struct BaseVtb{
        void(*one)(Base*pthis);
        void(*two_a_b)(Base*pthis,int a, int b);
        void(*two_a)(Base*pthis, int a);
    }BaseVtb;
    struct Base{
        const BaseVtb* pVtbl;
    };

Multiple inheritance
+++++++++++++++++++++++++
.. code::

    // this beat
    class Base{
        virtual void run() = 0;
        virtual void tryDo() = 0;
    };
    class A{
        virtual one(){
            // this is 0xxxx00 + offset of Base, that is not we want
            Base* p = reinterpret_cast<Base*>(this); // bad
            p->tryDo();
        }

        virtual one_withSuper(Base*self){
            Base* p = reinterpret_cast<Base*>(self);
        }
    };

    class B : public Base, public A{
        void run(){
            // this is 0xxxx00
            one();

            //diff
            one_withSuper(this);
        }
        void tryDo(){
            ...
        }
    };

Interesting
++++++++++++++++++++++
.. code::

    class Task{
        using CallBack = std::functional<void(Task*)>; 
        Task(CallBack&& cb){
            m_cb = std::move(cb);
        }
    }

    Task* creatTask(std::functional<void(Task*)> cb){
        Task* obj = new Task(cb);
        return obj;
    }

    Task* task =  creatTask([](Task* task){
        ...
    });