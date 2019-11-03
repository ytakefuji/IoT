import pyrealtime as prt

if __name__ == '__main__':
 s= prt.SerialReadLayer(device_name='COM3', baud_rate=115200)
 prt.TimePlotLayer(s, window_size=50, ylim=(-10, 500))
 prt.LayerManager.session().run()

