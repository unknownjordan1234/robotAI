// main.cpp
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QTcpSocket>
#include <iostream>
#include "Logger.h"

class V2RayApp : public QWidget {
    Q_OBJECT

public:
    V2RayApp(const std::string& ip, int port, QWidget *parent = nullptr) 
        : QWidget(parent), logger("app.log"), serverIp(ip), serverPort(port) {
        QVBoxLayout *layout = new QVBoxLayout(this);
        QPushButton *connectButton = new QPushButton("Connect to Proxy", this);

        layout->addWidget(connectButton);
        setLayout(layout);

        connect(connectButton, &QPushButton::clicked, this, &V2RayApp::connectToProxy);
    }

private slots:
    void connectToProxy() {
        try {
            QTcpSocket *socket = new QTcpSocket(this);
            socket->connectToHost(QString::fromStdString(serverIp), serverPort);

            if (socket->waitForConnected(3000)) {
                logger.log("Connected to server: " + serverIp + ":" + std::to_string(serverPort));
                std::cout << "Connected to server!" << std::endl;
            } else {
                throw std::runtime_error("Connection failed: " + socket->errorString().toStdString());
            }

            socket->close();
        } catch (const std::exception& e) {
            logger.log("Error: " + std::string(e.what()));
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

private:
    Logger logger;
    std::string serverIp;
    int serverPort;
};

int main(int argc, char *argv[]) {
    // Parameters for the server IP and port
    std::string serverIp = "localhost"; // Default value
    int serverPort = 1080; // Default value

    // Initialize QApplication
    QApplication app(argc, argv);
    V2RayApp window(serverIp, serverPort);
    window.setWindowTitle("V2Ray-Like Client");
    window.resize(400, 200);
    window.show();
    return app.exec();
}
