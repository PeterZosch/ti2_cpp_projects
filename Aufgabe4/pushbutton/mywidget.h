//#ifndef MYWIDGET_H
//#define MYWIDGET_H
 
#include <QtGui>
#include <QWidget>
 
class MyWidget : public QWidget
{
    Q_OBJECT
	
signals:
    void mouseClickEvent();

public:

protected:
	void mouseReleaseEvent ( QMouseEvent * e );
	void mousePressEvent ( QMouseEvent * e );
	 
private:
	QPolygonF rlccurve;
    void paintEvent(QPaintEvent *event);
	void compute(); 
	QPoint m_lastPoint;
	bool m_mouseClick;
};
 
//#endif // MYWIDGET_H
