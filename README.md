🎬 Sistema de Gestión para un Cine

Este proyecto tiene como objetivo el desarrollo de un sistema integral para la administración de un cine, permitiendo tanto a empleados como a clientes interactuar con la cartelera, funciones y ventas de manera eficiente y organizada.

🧰 Funcionalidades principales
👨‍💼 Empleados
🎞️ Gestión de películas, funciones y salas
* Modificación de precios y fechas de funciones

* Generación de informes de recaudación:

*Mensual / Anual

*Por función / película

*Por vendedor / medio de pago

📋 Listados completos de todas las entidades del sistema

* Clientes
* Consulta de precios y funciones disponibles

* Visualización de cartelera y horarios

* Realización de compras de entradas

🗃️ Estructura de datos
* Venta
* ID venta

* ID empleado

* ID función

*Cantidad de entradas

* Fecha

* Forma de pago

* Importe total

👥 Persona (Clase base)
* Nombre

* Apellido

* DNI

* Email

* Teléfono

🙋 Cliente (Hereda de Persona)
* ID cliente

* Teléfono

* Email

* DNI

*Nombre

* Apellido

🧑‍💼 Vendedor (Hereda de Persona)
*ID vendedor

* Sueldo

* Teléfono

* Email

* DNI

*Nombre

* Apellido

📅 Película
* ID película

* Título

* Género

* Duración

📅 Función
* ID función

* ID sala

* ID película

* Fecha

* Precio

* Sala

* ID sala

