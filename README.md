Password Manager in C

Un'applicazione CLI sicura per generare, memorizzare e gestire password crittografate. Utilizza SQLite per l'archiviazione sicura e OpenSSL per la crittografia, garantendo la protezione dei dati.

🚀 Funzionalità

✅ Generazione di password sicure

Generazione di password casuali con lettere, numeri e simboli.

L'utente può specificare la lunghezza della password.

✅ Memorizzazione sicura delle password

Le password vengono crittografate prima di essere salvate nel database SQLite.

Ogni password è associata a un nome utente e un servizio (es. Facebook, Gmail, etc.).

✅ Recupero delle password

L'utente può recuperare una password fornendo il nome del servizio.

La password viene decrittata prima di essere mostrata.

✅ Eliminazione di una password

L'utente può rimuovere una password specifica dal database.

✅ Autenticazione con Master Password

Per maggiore sicurezza, l'accesso ai dati è protetto da una master password che l'utente deve inserire all'avvio.

🛠️ Tecnologie Utilizzate

🗄️ SQLite → Database leggero per memorizzare le password in modo strutturato.

🔐 OpenSSL → Per crittografare e decrittografare le password.

📜 Libreria standard di C → Per la gestione dell'input/output e la generazione di password casuali.

📥 Installazione

1️⃣ Clonare il repository

    git clone https://github.com/tuo-username/password-manager-c.git
    cd password-manager-c

2️⃣ Compilare il programma

Assicurati di avere GCC e OpenSSL installati.

    make

3️⃣ Eseguire il programma

    ./password_manager

🔧 Utilizzo

Aggiungere una password

Avvia il programma e inserisci la master password.

Scegli l'opzione 1 per aggiungere una nuova password.

Inserisci il nome del sito/servizio, il nome utente e la password.

Recuperare una password

Avvia il programma e inserisci la master password.

Scegli l'opzione 2 per cercare una password salvata.

Inserisci il nome del sito/servizio.

Eliminare una password

Avvia il programma e inserisci la master password.

Scegli l'opzione 3 per eliminare una password.

Inserisci il nome del sito/servizio da rimuovere.

Uscire

Seleziona 4 per uscire dal programma.

🔒 Sicurezza

Le password vengono crittografate con AES-256 prima di essere salvate.

L'utente deve autenticarsi con una master password per accedere ai dati.

📜 Licenza

Questo progetto è distribuito sotto la licenza MIT. Sentiti libero di modificarlo e migliorarlo!

🤝 Contributi

Contributi e suggerimenti sono benvenuti! Puoi aprire una Pull Request o segnalare problemi con una Issue.

📌 Nota: Questo progetto è a scopo educativo. Non utilizzare in ambienti di produzione senza un'adeguata revisione della sicurezza.