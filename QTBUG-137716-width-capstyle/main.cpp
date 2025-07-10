#include <QApplication>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QPen>
#include <QDebug>

// Explicitly use the QtCharts namespace
// QT_CHARTS_USE_NAMESPACE

    int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create the line series
    QLineSeries *series = new QLineSeries();
    series->append(0, 0);
    series->append(1, 2);
    series->append(2, 1);

    // Set pen style
    QPen pen(Qt::blue);
    pen.setWidthF(4.5);
    pen.setCapStyle(Qt::RoundCap);
    series->setPen(pen);

    // Print cap style and width
    qDebug() << "Cap Style:" << series->pen().capStyle();  // Qt::RoundCap = 0x20
    qDebug() << "Line Width:" << series->pen().widthF();   // 4.5

    // Create chart and add series
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Line Series CapStyle and Width Demo");

    // Create chart view
    QChartView *view = new QChartView(chart);
    view->setRenderHint(QPainter::Antialiasing);
    view->resize(600, 400);
    view->show();

    return app.exec();
}
