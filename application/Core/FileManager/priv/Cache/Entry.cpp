#include "Entry.h"
using namespace FileManager;


Entry::Entry(const QString& name)
   : name(name)
{
}

qint64 Entry::getSize()
{
   return this->size;
}