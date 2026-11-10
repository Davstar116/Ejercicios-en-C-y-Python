import string
import random
import time

# Función para generar palabras
def generar_lista_palabras(n):
    letras = string.ascii_lowercase
    lista_palabras = []

    for _ in range(n):
        palabra = ""
        for _ in range(4):
            letra = random.choice(letras)
            palabra += letra
        lista_palabras.append(palabra)
    
    return lista_palabras

def main():
    n = 100000
    lista_palabras = generar_lista_palabras(n)
    
    # Solicitar palabra
    palabra_buscar = input("Introduce una palabra de cuatro letras: ")

    # Tiempo de ejecución
    inicio = time.time()
    encontrada = False
    for palabra in lista_palabras:
        if palabra == palabra_buscar:
            encontrada = True
            break
    fin = time.time()

    # Resultado de la búsqueda
    if encontrada:
        print(f"La palabra '{palabra_buscar}' fue encontrada en la lista.")
    else:
        print(f"La palabra '{palabra_buscar}' no se encontró en la lista.")
    
    print(f"Tiempo de búsqueda: {fin - inicio:.4f} segundos")

if __name__ == "__main__":
    main()
