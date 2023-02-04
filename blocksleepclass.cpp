#include "blocksleepclass.h"
#include <windows.h>
#include <QDebug>
BlockSleepClass::BlockSleepClass()
{

}

void BlockSleepClass::run()
{
    while(true){
        while (true){
            SetThreadExecutionState(ES_CONTINUOUS|ES_DISPLAY_REQUIRED);
            QThread::msleep(10000);
            qDebug() << "正在防止阻止睡眠";
        }
    }
}
