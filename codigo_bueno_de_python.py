import threading, serial, os, socket

# 0 bomba de agua 
bomba = False
# 2 Medidor de humedad de tierra
tierra = 0
# 3 Sensor de agua
agua = False
#4 Medidor de luz
luminosidad = 0
# 5 Sensor de gases
gas = 0
# 6 Sensor de ultrasonido
nivelAgua = 0
# 7 Sensor de temperatura
temp = 0
hume = 0
# ver si placa esta on
conectada = False
arduino = 0



def leerArduino():
    global bomba, tierra, agua, luminosidad, gas, nivelAgua, temp, hume, conectada, arduino

    while True:
    
        placa = os.path.exists('/dev/ttyACM0')
        placa2 = os.path.exists('/dev/ttyACM1')
        
        if placa == True and conectada == False:
            conectada = True
            print("Escuchando de arduino...")
            arduino = serial.Serial('/dev/ttyACM0', 9600)
        elif placa == False:
            if placa2 == True:
                arduino = serial.Serial('/dev/ttyACM1', 9600)
                print("Puerto cambiado")
            conectada = False
        
        while arduino.inWaiting() > 0:
            ms = arduino.readline().decode('utf-8')
            recibido = list(ms.split(','))
            recibido.remove('\r\n')
            
            print("Arduino recibido: ", recibido)
            
            if len(recibido) == 8:
                # 0 bomba de agua 
                bomba = int(recibido[0])
                # 2 Medidor de humedad de tierra
                tierra = int(recibido[1])
                # 3 Sensor de agua
                agua = int(recibido[2])
                #4 Medidor de luz
                luminosidad = int(recibido[3])
                # 5 Sensor de gases
                gas = int(recibido[4])
                # 6 Sensor de ultrasonido 
                nivelAgua = int(recibido[5])
                # 7 Sensor de temperatura
                temp = float(recibido[6])
                hume = float(recibido[7])
            
def servidorSocket():
    global bomba, tierra, agua, luminosidad, gas, nivelAgua, temp, hume, conectada, arduino
    # crear socket
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # vincular ip de raspberry
    s.bind(('192.168.1.99', 9000))
    s.listen(2)
    
    print("Servidor socket arrancado")
    # empezar a escuchar clients
    client, address = s.accept()
    print("Cliente conectado:", address)

    while True:
        # leer datos del cliente
        data = client.recv(1024).decode('utf-8')
        
        print("Socket recibido: ", data)
        # mandar a la aplicacion movil 
        if data == "manda":
            mensaje = str(bomba)+ "|" +str(tierra)+"|" +str(agua)+ "|"+str(luminosidad)+ "|" +str(gas)+ "|"+ str(nivelAgua)+"|"+ str(temp)+ "|" +str(hume) 
            client.sendall(mensaje.encode())
            print("Datos al app: ", mensaje)
        # si no ha datos vuelve a escuchar
        if not data:
            print("Desconectado:", address)
            client, address = s.accept()
            print("Cliente conectado:", address)



if __name__ == '__main__':
    threading.Thread(target=leerArduino).start()
    threading.Thread(target=servidorSocket).start()
    
    
    
    
    
    
