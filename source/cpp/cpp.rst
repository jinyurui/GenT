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