 // Función para encender la alarma
 function encenderAlarma() {
    // Aquí puedes agregar el código para encender la alarma
    alert("Alarma encendida");
}

// Función para apagar la alarma
function apagarAlarma() {
    // Aquí puedes agregar el código para apagar la alarma
    alert("Alarma apagada");
}

// Función para obtener la temperatura y la humedad desde el ESP32
function obtenerDatos() {
    // Realizar una solicitud al servidor en el ESP32 para obtener los datos
    // Esto puede ser mediante una solicitud AJAX o mediante WebSockets, dependiendo de tu configuración

    // Ejemplo de actualización de datos (sustituir con datos reales obtenidos del ESP32)
    var temperatura = 25; // Obtener temperatura desde ESP32
    var humedad = 60; // Obtener humedad desde ESP32

    // Actualizar los elementos en la página con los nuevos datos
    document.getElementById("tempValor").innerText = temperatura;
    document.getElementById("humValor").innerText = humedad;
}

// Llamar a la función para obtener los datos cada cierto intervalo de tiempo (por ejemplo, cada 5 segundos)
setInterval(obtenerDatos, 5000); // Intervalo de 5000 milisegundos (5 segundos)