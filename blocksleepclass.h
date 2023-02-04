#ifndef BLOCKSLEEPCLASS_H
#define BLOCKSLEEPCLASS_H
#include <QThread>
#include <QObject>

class BlockSleepClass : public QThread
{
    Q_OBJECT
public:
    explicit BlockSleepClass();
protected:
    void run() override;
signals:

};

#endif // BLOCKSLEEPCLASS_H
