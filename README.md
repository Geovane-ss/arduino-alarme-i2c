# 🔐 Projeto Arduino - Sistema de Alarme com I2C

## 📋 Descrição (Description)

Este projeto utiliza dois Arduinos Uno comunicando-se através do protocolo I2C. Um atua como **mestre** e o outro como **escravo**, formando um sistema de alarme com sensor PIR para detecção de movimento, LEDs e buzzers.

This project uses two Arduino Uno boards communicating via the I2C protocol. One acts as the **master** and the other as the **slave**, forming an alarm system using a PIR motion sensor, LEDs, and buzzers.

---

## 🔧 Componentes Utilizados (Components Used)

- 2x Arduino Uno
- 1x Sensor PIR
- 2x Buzzers
- 2x LEDs
- 2x Resistores 220Ω (para os LEDs)
- Jumpers
- Protoboard

---

## 🔗 Comunicação I2C

- **Master SDA → Slave SDA** (A4 → A4)
- **Master SCL → Slave SCL** (A5 → A5)
- GND de ambos conectados

---

## 🚦 Funcionamento (How It Works)

| Estado | Ação |
|--------|------|
| `DESARMAR` | Desativa LEDs, buzzers e sensor |
| `ARMAR` | Ativa LEDs que piscam e o sensor PIR |
| `MOVIMENTO` | Ambos os buzzers tocam e LEDs acendem fixos |
| `DESARMAR` | Alarme para imediatamente |

No Arduino Mestre, o usuário envia comandos (`ARMAR` ou `DESARMAR`) pelo **monitor serial**. O Mestre envia o comando ao Escravo via I2C. Se movimento for detectado, o Escravo avisa o Mestre, que ativa o alarme.

---

## 🗂 Estrutura do Projeto

arduino-alarme-i2c/
│
├── mestre/

│ └── mestre.ino
│
├── escravo/

│ └── escravo.ino
│

└── README.md

---

## 💻 Como Usar

1. Abra o **Arduino IDE**
2. Copie o código da pasta `mestre/` no Arduino Uno Mestre
3. Copie o código da pasta `escravo/` no Arduino Uno Escravo
4. Conecte os fios conforme o esquema
5. Use o **monitor serial** para enviar os comandos `ARMAR` ou `DESARMAR`

---

## 📜 Licença

Este projeto é livre para fins educacionais.

---

## 📸 Imagens do Projeto / Project Images

![image](https://github.com/user-attachments/assets/63f62281-e03d-4137-89f7-ff54e31ba213)

---

## 🤝 Autor / Author

**Geovane**

📧 [meugit.geovane.hub@gmail.com]  
💼 [Linkedin: https://www.linkedin.com/in/geovane-vitor-b7540716b]
