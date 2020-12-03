import socket

# crear socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# vincular ip de raspberry
s.bind(('localhost', 9000))
s.listen(2)

# empezar a escuchar clients
client, address = s.accept()
print("Cliente conectado:", address)

while True:
    # leer datos del cliente
    data = client.recv(1024).decode('utf-8')
    
    # si no ha datos vuelve a escuchar
    if not data:
        print("Desconectado:", address)
        client, address = s.accept()
        print("Cliente conectado:", address)
        
        
        
        
        
        
        