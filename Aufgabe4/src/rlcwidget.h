#include <QtGui>
#include <QWidget>
 
class RLCWidget : public QWidget
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
	int click = 0;
};
