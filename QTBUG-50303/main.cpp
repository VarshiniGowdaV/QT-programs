#include <QApplication>
#include <QTextBrowser>
#include <QTextCursor>
#include <QTextCharFormat>
#include <QUrl>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTextBrowser editor;
    editor.setReadOnly(true); // Prevent editing

    QTextCursor cursor = editor.textCursor();

    // Anchor with NO formatting (still clickable)
    QTextCharFormat anchorFormat;
    anchorFormat.setAnchor(true);
    anchorFormat.setAnchorHref("https://www.qt.io");

    // By default, no underline or color is set, so it appears as normal text
    cursor.insertText("This link has NO underline or color.\n", anchorFormat);

    // Make sure external links are handled by your slot, not default browser
    editor.setOpenExternalLinks(false);

    QObject::connect(&editor, &QTextBrowser::anchorClicked, [](const QUrl &url){
        qDebug() << "Link clicked:" << url;
    });

    editor.show();
    return app.exec();
}


// #include <QApplication>
// #include <QTextBrowser>
// #include <QTextCursor>
// #include <QTextCharFormat>
// #include <QColor>
// #include <QUrl>
// #include <QDebug>

// int main(int argc, char *argv[])
// {
//     QApplication app(argc, argv);

//     QTextBrowser editor;
//     editor.setReadOnly(true); // Prevent editing

//     QTextCursor cursor = editor.textCursor();

//     // Anchor with UNDERLINE and BLUE color
//     QTextCharFormat anchorFormat;
//     anchorFormat.setAnchor(true);
//     anchorFormat.setAnchorHref("https://www.qt.io");
//     anchorFormat.setFontUnderline(true);
//     anchorFormat.setForeground(QColor("blue"));

//     cursor.insertText("This link is underlined and blue.\n", anchorFormat);

//     // Ensure clicks are handled by anchorClicked signal
//     editor.setOpenExternalLinks(false);

//     QObject::connect(&editor, &QTextBrowser::anchorClicked, [](const QUrl &url){
//         qDebug() << "Link clicked:" << url;
//     });

//     editor.show();
//     return app.exec();
// }
