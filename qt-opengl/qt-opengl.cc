/*
  qt-opengl.cc
  
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

#include "qt-core.h"

#include "QC_QGLWidget.h"
#include "QC_QGLFormat.h"
#include "QC_QGLContext.h"
#include "QC_QGLColormap.h"
#include "QC_QGLFramebufferObject.h"
#include "QC_QGLPixelBuffer.h"

#include "QC_QWidget.h"
#include "QC_QPaintDevice.h"
#include "QC_QObject.h"

static QoreStringNode *qt_opengl_module_init();
static void qt_opengl_module_ns_init(QoreNamespace *rns, QoreNamespace *qns);
static void qt_opengl_module_delete();

DLLEXPORT char qore_module_name[] = "qt-opengl";
DLLEXPORT char qore_module_version[] = PACKAGE_VERSION;
DLLEXPORT char qore_module_description[] = "QT 4 OpenGL module";
DLLEXPORT char qore_module_author[] = "David Nichols";
DLLEXPORT char qore_module_url[] = "http://qore.org";
DLLEXPORT int qore_module_api_major = QORE_MODULE_API_MAJOR;
DLLEXPORT int qore_module_api_minor = QORE_MODULE_API_MINOR;
DLLEXPORT qore_module_init_t qore_module_init = qt_opengl_module_init;
DLLEXPORT qore_module_ns_init_t qore_module_ns_init = qt_opengl_module_ns_init;
DLLEXPORT qore_module_delete_t qore_module_delete = qt_opengl_module_delete;
DLLEXPORT const char *qore_module_dependencies[] = { "qt-gui", "opengl", 0 };
// assume LGPL for qt >= 4.5
#if QT_VERSION >= 0x040500
DLLEXPORT qore_license_t qore_module_license = QL_LGPL;
#else
DLLEXPORT qore_license_t qore_module_license = QL_GPL;
#endif

static QoreNamespace gl_ns("QtOpenGL");

static void init_namespace() {
   gl_ns.addSystemClass(initQGLWidgetClass(QC_QWidget));
   gl_ns.addInitialNamespace(initQGLFormatNS());
   gl_ns.addInitialNamespace(initQGLNS());
   gl_ns.addSystemClass(initQGLContextClass());
   gl_ns.addSystemClass(initQGLColormapClass());
   gl_ns.addInitialNamespace(initQGLFramebufferObjectNS(QC_QPaintDevice));
   gl_ns.addSystemClass(initQGLPixelBufferClass(QC_QObject));
}

static QoreStringNode *qt_opengl_module_init() {
   // initialize namespace
   init_namespace();

   return 0;
}

static void qt_opengl_module_ns_init(QoreNamespace *rns, QoreNamespace *qns) {
   qns->addInitialNamespace(gl_ns.copy());
}

static void qt_opengl_module_delete() {
}
