#ifndef ARDUINOLIEU_H
#define ARDUINOLIEU_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

class arduinolieu
{
public:
    arduinolieu();
    int connect_arduino_lieu(); // permet de connecter le PC à Arduino
    int close_arduino_lieu(); // permet de femer la connexion
    int write_to_arduino_lieu( QByteArray ); // envoyer des données vers arduino
    QByteArray read_from_arduino_lieu();  //recevoir des données de la carte Arduino
    QSerialPort* getserial();   // accesseur
    QString getarduino_port_name();
private:
QSerialPort * serial; //Cet objet rassemble des informations (vitesse, bits de données, etc.)
//et des fonctions (envoi, lecture de réception,…) sur ce qu’est une voie série pour Arduino.
static const quint16 arduino_uno_vendor_id=9025;
static const quint16 arduino_uno_producy_id=67;
QString arduino_port_name;
bool arduino_is_available;
QByteArray data_lieu;  // contenant les données lues à partir d'Arduino
};

#endif // ARDUINOLIEU_H
