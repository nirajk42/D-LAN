#ifndef CHAT_H
#define CHAT_H

#include <QObject>

#include <QtNetwork/QNetworkInterface>
#include <QtNetwork/QUdpSocket>

/**
  * An instance of this class will listen for UDP datagram on a certain port and IP (class D).
  * see : http://tldp.org/HOWTO/Multicast-HOWTO-2.html#ss2.1
  * When a message is received it will print it.
  * Multicast nessages can be sended with 'sendMessage'.
  */
class Chat : public QObject
{
   Q_OBJECT
   
public:
    Chat();
    virtual ~Chat();
    
    /**
      * Send a broadcast message.
      * @param mess The message to send.
      */
    void sendMessage(const QString& mess);

private slots:
    /**
      * When a datagram is received this slot is called.
      */
    void processPendingDatagrams();
    
private:
    QUdpSocket* socket;
    
    static const char TTL; ///< Time to live, see the UDP multicast documentation.
    static const int port;
    static QHostAddress multicastIP; ///< A choosen multicast address channel used to send and received messages.
};

#endif // CHAT_H
