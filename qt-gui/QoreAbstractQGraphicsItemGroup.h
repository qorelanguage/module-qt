/*
 QoreAbstractQGraphicsItemGroup.h
 
  Qore Programming Language

 Copyright 2003 - 2008 David Nichols

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 
 */

#ifndef _QORE_QT_QOREABSTRACTQGRAPHICSITEMGROUP_H

#define _QORE_QT_QOREABSTRACTQGRAPHICSITEMGROUP_H

#include "QoreAbstractQGraphicsItem.h"

class QoreAbstractQGraphicsItemGroup : public QoreAbstractQGraphicsItemData
{
   public:
      DLLLOCAL virtual QGraphicsItemGroup *getQGraphicsItemGroup() const = 0;
};

template<typename T, typename V>
class QoreQGraphicsItemGroupBase : public QoreQGraphicsItemBase<T, V>
{
   public:
      DLLLOCAL QoreQGraphicsItemGroupBase(T *qo) : QoreQGraphicsItemBase<T, V>(qo)
      {
      }

      DLLLOCAL virtual QGraphicsItemGroup *getQGraphicsItemGroup() const
      {
         return static_cast<QGraphicsItemGroup *>(&(*this->qobj));
      }
};

template<typename T, typename V>
class QoreQtQGraphicsItemGroupBase : public QoreQtQGraphicsItemBase<T, V>
{
   public:
      DLLLOCAL QoreQtQGraphicsItemGroupBase(T *qo, bool managed = true) : QoreQtQGraphicsItemBase<T, V>(qo, managed)
      {
      }

      DLLLOCAL virtual QGraphicsItemGroup *getQGraphicsItemGroup() const
      {
         return this->qobj;
      }
};

#endif  // _QORE_QT_QOREABSTRACTQGRAPHICSITEMGROUP_H
