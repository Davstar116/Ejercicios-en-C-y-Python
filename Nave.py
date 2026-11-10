import math

def calcular_nueva_posicion(radio, angulo):
    """
    Calcula las nuevas coordenadas del satélite después de desplazarse un cierto ángulo en su órbita circular.
    
    Parámetros:
    radio -- El radio de la órbita del satélite
    angulo -- El ángulo en grados al que se ha movido el satélite
    
    Retorna:
    Una tupla (x2, y2) que representa las nuevas coordenadas del satélite.
    """
    x2 = radio * math.cos(math.radians(angulo))
    y2 = radio * math.sin(math.radians(angulo))
    return x2, y2

def calcular_diferencia_distancia(x1, y1, x2, y2, px, py):
    """
    Calcula la diferencia en las distancias entre la nave espacial y las posiciones inicial y final del satélite.
    
    Parámetros:
    x1, y1 -- Coordenadas iniciales del satélite
    x2, y2 -- Coordenadas finales del satélite después de desplazarse
    px, py -- Coordenadas de la nave espacial
    
    Retorna:
    La diferencia en las distancias d1 y d2.
    """
    d1 = math.sqrt((x1 - px)**2 + (y1 - py)**2)
    d2 = math.sqrt((x2 - px)**2 + (y2 - py)**2)
    return abs(d1 - d2)

# Coordenadas iniciales
x1, y1 = 100, 0
px, py = 100, 0

# Parámetros de entrada
radio = 100
angulo = float(input("Ingrese el ángulo en grados al que se ha movido el satélite: "))

# Nuevas coordenadas
x2, y2 = calcular_nueva_posicion(radio, angulo)

# Calcular diferencia
diferencia = calcular_diferencia_distancia(x1, y1, x2, y2, px, py)

print(f"La diferencia en las distancias es: {diferencia:.2f}")