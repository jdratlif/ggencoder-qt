TEMPLATE = app
TARGET = ggencoder
QT += widgets
DEPENDPATH += . exceptions model tools view
INCLUDEPATH += .

HEADERS += exceptions/invalidgamegeniecode.hh \
           model/comparerawcode.hh \
           model/gamegeniecode.hh \
           model/gbgggamegeniecode.hh \
           model/gbggrawcode.hh \
           model/genesisgamegeniecode.hh \
           model/genesisrawcode.hh \
           model/nesgamegeniecode.hh \
           model/nesrawcode.hh \
           model/rawcode.hh \
           model/snesgamegeniecode.hh \
           model/snesrawcode.hh \
           tools/decoder.hh \
           tools/encoder.hh \
           view/geniedialog.hh \
           view/system.hh
           
FORMS += view/maindialog.ui

SOURCES += ggencoder.cc \
           exceptions/invalidgamegeniecode.cc \
           model/comparerawcode.cc \
           model/gamegeniecode.cc \
           model/gbgggamegeniecode.cc \
           model/gbggrawcode.cc \
           model/genesisgamegeniecode.cc \
           model/genesisrawcode.cc \
           model/nesgamegeniecode.cc \
           model/nesrawcode.cc \
           model/rawcode.cc \
           model/snesgamegeniecode.cc \
           model/snesrawcode.cc \
           tools/decoder.cc \
           tools/encoder.cc \
           view/geniedialog.cc

