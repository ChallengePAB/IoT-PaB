# ⚽ Controle de Temperatura e Umidade em Campos de Futebol 


## 📖 Sobre o Projeto

O projeto Controle de Temperatura e Umidade nos Campos de Futebol tem como objetivo monitorar as condições climáticas do gramado em tempo real, utilizando um microcontrolador ESP32, comunicação HTTP e integração com um dashboard web.

Essa solução permite acompanhar temperatura e umidade de forma contínua, ajudando na manutenção do gramado, prevenção de superaquecimento e otimização da irrigação, garantindo melhores condições de jogo e preservação do campo.

## 🧠 Funcionamento Geral

O ESP32 simula ou coleta dados reais dos sensores (como DHT11/DHT22).

Esses dados são enviados via HTTP POST para um endpoint configurado no Render.

A resposta do servidor confirma o recebimento.

Um dashboard web (frontend) consome esses dados e os exibe graficamente em tempo real, permitindo análise e tomada de decisão.

## 📊 Integração com o Dashboard Web

O dashboard foi projetado para consumir os dados JSON e exibi-los de forma visual e interativa.

Principais elementos:

- Gráfico em tempo real: mostra variação da temperatura e umidade.

- Indicadores numéricos: exibição dos valores atuais.

- Alertas automáticos: exibe mensagens quando a temperatura ultrapassa limites definidos.

- Interface responsiva: pode ser acessada via computador, tablet ou celular.



**👉 LINK DO WOKWI ->** [Click aqui para acessar a simulação](https://wokwi.com/projects/446721568121464833)

**👉 LINK DO SITE ->** [Click aqui para acessar ao Site ](https://site-pab.vercel.app/encontros)

## 👩‍💻 Desenvolvedores 

- Julia Schiavi
- Thayna Lopes
- Sofia Bomeny
- Leonardo Grosskopf

