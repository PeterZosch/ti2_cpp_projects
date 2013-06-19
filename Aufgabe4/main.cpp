#include <QtGui>  
#include </usr/include/qwt/qwt_plot.h>
#include </usr/include/qwt/qwt_plot_curve.h>


class CosinusData: public QwtSyntheticPointData
{
public:
    CosinusData(size_t numberOfPoints):
        QwtSyntheticPointData(numberOfPoints)
    {
    }
    
    //This has to be overridden, because it is pure virtual in base class
    double y(double x) const
    {
        return qCos(x);
    }
};


int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  
    QwtPlot *myPlot = new QwtPlot(NULL);   
    
    // add curves
    QwtPlotCurve *curve1 = new QwtPlotCurve("Curve 1");
    QwtPlotCurve *curve2 = new QwtPlotCurve("Curve 2");
    
    myPlot->setFixedWidth(300);
    myPlot->setWindowTitle("Cosinus and Straight Line Graph");
    
    
    double x[3] ={0,10,15};
    double y[3] ={0,0,0};
    curve1->setData(new QwtCPointerData(&x[0],&y[0],(size_t)3));    
    
    //Create QwtSyntheticPointData (Cosinus data) with 1000 points
    //You can increase number of points to generate smoother graphs
    curve2->setData(new CosinusData(1000));
 
    
    curve1->attach(myPlot);
    curve2->attach(myPlot);
   
    // finally, refresh the plot
    myPlot->replot();
    myPlot->show();  
    
  return app.exec();
}
