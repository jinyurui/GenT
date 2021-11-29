GRPC
***************

Work flow
+++++++++++++++
- define proto
- build proto
- over server/client

proto
+++++++++++++++
... code::

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
... code::

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
