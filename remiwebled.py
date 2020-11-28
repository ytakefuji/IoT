import remi.gui as gui
from remi import start, App
import serial
s=serial.Serial('COM3',9600)

class MyApp(App):
    def __init__(self, *args):
        super(MyApp, self).__init__(*args)

    def main(self):
        container = gui.VBox(width=400, height=400,style={'font-size': '48px'})
        self.lbl = gui.Label('Web LED-ON and LED-OFF',style={'font-size': '48px'})
        self.bt = gui.Button('Press LED-ON',style={'font-size': '48px'})
        self.bt.onclick.do(self.on_button_pressed)
        self.ct = gui.Button('Press LED-ON',style={'font-size': '48px'})
        self.ct.onclick.do(self.off_button_pressed)
        container.append(self.lbl)
        container.append(self.bt)
        container.append(self.ct)
        return container

    def on_button_pressed(self, widget):
        self.lbl.set_text('Button LED-ON')
        s.write(bytes('on', 'UTF-8'))
        self.bt.set_text('LED-ON')
    def off_button_pressed(self, widget):
        self.lbl.set_text('Button LED-OFF')
        s.write(bytes('off', 'UTF-8'))
        self.ct.set_text('LED-OFF')

start(MyApp,address='127.0.0.1', port=8080, multiple_instance=False, enable_file_cache=True, update_interval=0.1, start_browser=True)
