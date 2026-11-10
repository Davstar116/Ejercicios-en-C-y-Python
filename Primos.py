def es_primo(n):
    """
    Determina si un número es primo.
    
    Parámetro:
    n -- El número a verificar
    
    Retorna:
    True si el número es primo, False en caso contrario.
    """
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def mostrar_primos(hasta):
    """
    Muestra todos los números primos hasta un valor especificado.
    
    Parámetro:
    hasta -- El límite superior hasta el cual se buscarán números primos.
    """
    for num in range(2, hasta + 1):
        if es_primo(num):
            print(num, end=" ")

def main():
    """
    Función principal que solicita al usuario un límite y muestra los números primos hasta ese valor.
    """
    try:
        limite = int(input("Desplegar los números primos hasta qué valor: "))
        mostrar_primos(limite)
    except ValueError:
        print("Por favor, ingrese un número entero válido.")

# Ejecutar programa
main()