import serial, os
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




while True:
    
    placa = os.path.exists('/dev/ttyACM0')
    
    if placa == True and conectada == False:
        conectada = True
        print("Escuchando de arduino...")
        arduino = serial.Serial('/dev/ttyACM0', 9600)
    elif placa == False:
        conectada = False
    
    while arduino.inWaiting() > 0:
        ms = arduino.readline().decode('utf-8')
        recibido = list(ms.split(','))
        recibido.remove('\r\n')
        
        print("Datos recibidos", recibido)
        
       
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
        
        
        
        # 2 Medidor de humedad de tierra
        if tierra < 50:
            print("La maceta está seca", tierra, "%")
        else:
            print("Humedad óptima:", tierra, "%")
        
        # 3 Sensor de agua
        if agua == 1:
            print("detecta agua", agua)
        else:
            print("no detecta agua", agua)
        
        #4 Medidor de luz
        if luminosidad < 40:
            print("Hay poca luz:", luminosidad, "%")
        else:
            print("Bien iluminado:", luminosidad, "%")
        
        # 5 Sensor de gases
        if gas < 50:
            print("poco gas:", gas, "%")
        else:
            print("gas correcto:", gas, "%")
        
        # 6 Sensor de ultrasonido
        if nivelAgua > 100:
             print("Nivel de Agua: Muy bajo", nivelAgua, "%")
        elif nivelAgua <= 10 and nivelAgua > 1:
            print("Nivel de Agua: Bajo", nivelAgua, "%")
        elif nivelAgua <= 10 and nivelAgua > 30:
            print("Nivel de Agua: Medio", nivelAgua, "%")
        elif nivelAgua <= 40 and nivelAgua > 60:
            print("Nivel de Agua: Alto", nivelAgua, "%")
        else:
            print("Nivel de Agua: Muy Alto", nivelAgua, "%")
        
        # 7 Sensor de temperatura
        if temp:
            print("Temperatura: ", temp, "C")
        if hume:
            print("Humedad: ", hume, "%")
        
        
        
