import configparser
from example_of_window import Ui_MainWindow
from PyQt5 import QtWidgets


class MyUI(Ui_MainWindow):
    def __init__(self, MainWindow):
        super(MyUI, self).__init__()
        self.setupUi(MainWindow)

        self.config = configparser.ConfigParser()
        self.config.read('settings.ini')
        self.config_section = self.config['SETTINGS']

        self.set_data_from_config_to_field()
        self.add_functions()

    def set_data_from_config_to_field(self):
        self.label.setText(self.config_section['LABEL_FIELD'])
        self.lineEdit.setText(self.config_section['TEXT_FIELD'])
        self.checkBox.setChecked(self.config_section.getboolean('CHECKBOX'))

    def add_functions(self):
        self.pushButton.clicked.connect(self.update_config)

    def update_config(self):
        self.config.set('SETTINGS', 'LABEL_FIELD', self.label.text())
        self.config.set('SETTINGS', 'TEXT_FIELD', self.lineEdit.text())
        self.config.set('SETTINGS', 'CHECKBOX', str(self.checkBox.isChecked()))

        with open('settings.ini', 'w') as configfile:
            self.config.write(configfile)


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = MyUI(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
