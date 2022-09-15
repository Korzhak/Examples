from example_of_window import Ui_MainWindow
from PyQt5 import QtCore, QtGui, QtWidgets


class MyUI(Ui_MainWindow):
    def __init__(self, MainWindow):
        super(MyUI, self).__init__()
        self.setupUi(MainWindow)
        self.add_points_to_combobox()
        self.update_label()

    def add_points_to_combobox(self):
        self.comboBox.addItem('Item 1')
        self.comboBox.addItem('Item 2')
        self.comboBox.addItem('Item 3')

    def update_label(self):
        self.label.setText('This is new text in label')


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = MyUI(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
