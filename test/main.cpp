
#include "ostprotolib.h"
#include "pcapfileformat.h"
#include "protocol.pb.h"
#include "protocolmanager.h"

#include <QCoreApplication>
#include <QString>

extern ProtocolManager *OstProtocolManager;

int main(int argc, char* argv[])
{
    bool isOk;
    QCoreApplication app(argc, argv);
    QString error;

    if (argc != 2)
    {
        printf("%s <infile>\n", argv[0]);
        exit(255);
    }

    OstProtocolManager = new ProtocolManager();

    OstProto::StreamConfigList streams;
    QString inFile(argv[1]);

    OstProtocolManager = new ProtocolManager();

    OstProtoLib::setExternalApplicationPaths(
            "c:/Program Files/Wireshark/Tshark.exe",
            "d:/srivatsp/projects/ostinato/pdml/bin/gzip.exe",
            "d:/srivatsp/projects/ostinato/pdml/bin/diff.exe",
            "d:/srivatsp/projects/ostinato/pdml/bin/gawk.exe");

    isOk = pcapFileFormat.openStreams(inFile, streams, error);
    if (!error.isEmpty())
    {
        printf("%s: %s\n", 
                inFile.toAscii().constData(), error.toAscii().constData());
    }

    if (!isOk)
        exit(1);

    return 0;
}
