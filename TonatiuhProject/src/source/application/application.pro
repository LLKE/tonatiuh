TEMPLATE = app

include( $$(TONATIUH_ROOT)/config.pri )

TARGET = Tonatiuh   

              
INCLUDEPATH += 	. \
			   $$(TONATIUH_ROOT)/src/auxiliary \
               $$(TONATIUH_ROOT)/src/geometry \
               $$(TONATIUH_ROOT)/src/nodes \
               $$(TONATIUH_ROOT)/src/plugins \
               $$(TONATIUH_ROOT)/src/raytracing \
               $$(TONATIUH_ROOT)/src/statistics \
               $$(TONATIUH_ROOT)/src/common
              
QT += core xml widgets
QT -= gui	


CONFIG(debug, debug|release) {
   	LIBS += -L$$(TONATIUH_ROOT)/bin/debug -lgeometry -lnodes -lstatistics -lraytracing -lstdc++fs
}else{
   	LIBS += -L$$(TONATIUH_ROOT)/bin/release -lgeometry -lnodes -lstatistics -lraytracing -lstdc++fs
}

unix {
   	LIBS += -ldl
}



# Input
HEADERS += 	$$(TONATIUH_ROOT)/src/auxiliary/Trace.h \
			$$(TONATIUH_ROOT)/src/auxiliary/Tracer.h \
			$$(TONATIUH_ROOT)/src/plugins/PluginManager.h \
			$$(TONATIUH_ROOT)/src/source/application/*.h 
                
SOURCES +=	$$(TONATIUH_ROOT)/src/auxiliary/Trace.cpp \
			$$(TONATIUH_ROOT)/src/auxiliary/Tracer.cpp \
			$$(TONATIUH_ROOT)/src/plugins/PluginManager.cpp \
			$$(TONATIUH_ROOT)/src/source/application/*.cpp 

#RESOURCES += tonatiuh.qrc
 

CONFIG(debug, debug|release) {
	DESTDIR = $$(TONATIUH_ROOT)/bin/debug
}
else{
	DESTDIR= $$(TONATIUH_ROOT)/bin/release
}
	
QMAKE_CLEAN -= *.rc  

src.target= src
QMAKE_EXTRA_TARGETS += src