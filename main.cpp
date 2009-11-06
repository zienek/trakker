#include <QApplication>
#include <QPixmap>
#include <QWidget>

#include "src/trakker.h"
#include "trakkercontroller.h"
#include "src/trakkermodel.h"

int main(int argc, char *argv[])
{
      Q_INIT_RESOURCE(application);
      QApplication app(argc, argv);

      trakkercontroller *pTrakkerContr = trakkercontroller::instance() ;
      pTrakkerContr->setMainWindow( new trakker() ) ;
      pTrakkerContr->setModel( new trakkermodel() ) ;

      pTrakkerContr->connectMua();

      pTrakkerContr->getWindow()->show() ;

      return app.exec();
}
