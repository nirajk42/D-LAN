#include <Builder.h>
using namespace LM;

#include <ILogger.h>
#include <priv/Logger.h>

QSharedPointer<ILogger> Builder::newLogger(const QString& name)
{
   return QSharedPointer<ILogger>(new Logger(name));
}
