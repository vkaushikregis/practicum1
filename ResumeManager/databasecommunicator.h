#ifndef DATABASECOMMUNICATOR_H
#define DATABASECOMMUNICATOR_H
#include <QtSql>
#include <QSql>
#include <QSqlDatabase>
#include "globalproductdata.h"

class DatabaseCommunicator
{
public:
    static DatabaseCommunicator* Instance();
    ~DatabaseCommunicator();
    bool getExistingResumesFromDB(std::string &msg);
    bool getPersonalDetailFromDB(int resume_fk,ResumeManagerBase &resuObj,std::string &msg);
    bool getAddressFromDB(int resume_fk,ResumeManagerBase &resuObj,std::string &msg);
    bool getEducationDetailsFromDB(int resume_fk,ResumeManagerBase &resuObj,std::string &msg);
    bool getWorkExDetailsFromDB(int resume_fk,ResumeManagerBase &resuObj,std::string &msg);
    bool getTechnicalSkillsFromDB(int resume_fk,ResumeManagerBase &resuObj,std::string &msg);

    bool insertResumeInformationInDB(const ResumeManagerBase &resuObj,std::string &msg);
private:
    DatabaseCommunicator();
    static DatabaseCommunicator *_instance;

    QString userName;
    QString password;
    QString databaseName;
    QString hostName;
    QSqlDatabase db;
};

#endif // DATABASECOMMUNICATOR_H
