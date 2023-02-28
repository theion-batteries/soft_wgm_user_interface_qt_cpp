#include <QObject>
#include "cntAlignController.h"
#include "cntAlignView.h"

class CntViewTest: public QObject {
    Q_OBJECT
public: 
  explicit CntViewTest(QObject *parent = 0);
signals:
 
private slots:
   void first();
   void on_cnt_connect_motion_axis_clicked();
private:
   cntAlignView cnt_align_view;
};


