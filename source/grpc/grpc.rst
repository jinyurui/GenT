GRPC
***************

Work flow
+++++++++++++++
- define proto
- build proto
- over server/client

proto
+++++++++++++++
.. code::

    syntax = "proto3";

    package ABC;

    import "google/protobuf/empty.proto";

    message Req {
        string arg = 1;
    }

    message Res {
        int32 value = 1;
    }
    
    service Demo {
        rpc normalEmpty (Req) returns (google.protobuf.Empty) {}
        rpc streamReq (stream Req) returns (google.protobuf.Empty) {}
        rpc streamRes (Req) returns (stream Res) {}
        rpc streamStream (stream Req) returns (stream Res) {}
    }

grpc
+++++++++++++++
- chanel ip::port
- stub
- context config
- reader/writer


Call Tables
+++++++++++++++

Async client
+++++++++++++++
.. code::

    Client{
        call{
            Res;
            context;
            status;
            ClientAsyncResponseReader
        }
        stub;
        cq;
        workThread;
        ~self{
           cq.shutdown;
           workThread.join;
           delete workThread;     
        }
        create{
            chanel;
            stub = package::service::NewStub(chanel);
        }
        sendReq{
            new call;
            Req req;
            call.reader = stub.prepareAsync{$fun}(call.context, req, &cq);
            call.reader.startCall;
            call.reader.finish(&call.res, &call.status, (void*)call);
        }
        workThread{
            void *got;
            bool ok;
            while(cq.next(&got, &ok)){
                Call *call = static_cast<Call*>(got);
                if(call.status.isOK){}
                delete call;
            }
        }
    }

Async server
+++++++++++++++
.. code::

    Server{
        std::unique_ptr<ServerCompletionQueue> cq_;
        service_;
        std::unique_ptr<Server> server_;

        CallData{
          T req;
          T res;
          context;
        }

        ~{
            server_->Shutdown();
            // Always shutdown the completion queue after the server.
            cq_->Shutdown();
        }
        create{
            std::string server_address("0.0.0.0:50051");

            ServerBuilder builder;
            // Listen on the given address without any authentication mechanism.
            builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

            // Register "service_" as the instance through which we'll communicate with
            // clients. In this case it corresponds to an *asynchronous* service.
            builder.RegisterService(&service_);

            // Get hold of the completion queue used for the asynchronous communication
            // with the gRPC runtime.
            cq_ = builder.AddCompletionQueue();
            
            // Finally assemble the server.
            server_ = builder.BuildAndStart();
            std::cout << "Server listening on " << server_address << std::endl;
        }

        Run{

        }

    }