/*
Copyright (C) 2010, 2014 Srivats P.

This file is part of "Ostinato"

This is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>
*/

#ifndef _RPC_SERVER_H
#define _RPC_SERVER_H

#include "sharedprotobufmessage.h"

#include <QTcpServer>

// forward declaration
namespace google {
    namespace protobuf {
        class Service;
        class Message;
    }
}

class RpcServer : public QTcpServer
{
    Q_OBJECT

public:
    RpcServer(bool perConnLogs);    //! \todo (LOW) use 'parent' param
    virtual ~RpcServer();

    bool registerService(::google::protobuf::Service *service,
        QHostAddress address, quint16 tcpPortNum);

signals:
    void notifyClients(int notifType, SharedProtobufMessage notifData);

protected:
    void incomingConnection(qintptr socketDescriptor);

private:
    ::google::protobuf::Service *service;
};

#endif
