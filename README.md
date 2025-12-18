# Banking Management System - C++

Un système de gestion bancaire simple mais complet développé en **C++** sous forme d'application console. Ce projet implémente une interface textuelle avec authentification multi-utilisateurs, gestion de clients, transactions bancaires, et un module de conversion de devises.

## Fonctionnalités principales

### 🔐 Authentification & Sécurité
- Écran de connexion avec **username** et **password**
- Limitation à **3 tentatives** de connexion
- Enregistrement automatique de l'historique des connexions (Login Register)
- Système de **permissions différenciées** :
  - **Admin (Permissions = 0)** : Accès complet à toutes les fonctionnalités
  - **Utilisateur limité (Permissions = -1)** : Accès **exclusif** au module Currency Exchange

### 👥 Gestion des Clients
- Afficher la liste complète des clients
- Ajouter un nouveau client
- Supprimer un client (par numéro de compte)
- Modifier les informations d'un client
- Rechercher un client par numéro de compte
- Affichage détaillé : Nom, prénom, email, téléphone, PIN, solde

### 💰 Transactions Bancaires
- Dépôt (Deposit)
- Retrait (Withdraw)
- Transfert entre comptes
- Affichage du solde total de la banque
- Historique des transferts

### 👤 Gestion des Utilisateurs (Admin uniquement)
- Lister tous les utilisateurs
- Ajouter un nouvel utilisateur
- Supprimer un utilisateur
- Modifier un utilisateur
- Rechercher un utilisateur

### 🌍 Currency Exchange (Conversion de Devises)
- Accessible par **tous les utilisateurs** (même limités)
- Lister les devises disponibles
- Rechercher une devise
- Mettre à jour les taux de change
- Calculateur de conversion

## Captures d'écran

![Login Screen](C:/Users/ASUS/Pictures/Screen_Shots/BankC++OOP/LoginScreen.png)  
![Main Menu](C:/Users/ASUS/Pictures/Screen_Shots/BankC++OOP/MainMenue.png)  
![Client List](C:/Users/ASUS/Pictures/Screen_Shots/BankC++OOP/ClientList.png)  
![Find Client](C:/Users/ASUS/Pictures/Screen_Shots/BankC++OOP/FindClient.png)  
![Transactions Menu](C:/Users/ASUS/Pictures/Screen_Shots/BankC++OOP/TransactionsMenu.png)  
![Manage Users](C:/Users/ASUS/Pictures/Screen_Shots/BankC++OOP/ManageUsers.png)  
![Currency Exchange](C:/Users/ASUS/Pictures/Screen_Shots/BankC++OOP/CurrencyExchange.png)  
![Access Denied](C:/Users/ASUS/Pictures/Screen_Shots/BankC++OOP/AccessDenied.png)

## Structure du projet
