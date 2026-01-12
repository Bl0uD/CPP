# CPP Module 00 - Introduction au C++

## 📚 Vue d'ensemble
Premier contact avec le C++. Ce module introduit les bases de la programmation orientée objet (POO) et les différences fondamentales entre C et C++.

---

## 🎯 Exercice 00 : Megaphone (megaphone.cpp)

### Concepts clés à maîtriser :

#### 1. **Différences C vs C++**

**En C :**
```c
#include <stdio.h>
printf("Hello\n");
```

**En C++ :**
```cpp
#include <iostream>
std::cout << "Hello" << std::endl;
```

#### 2. **Flux d'entrée/sortie (iostream)**
```cpp
#include <iostream>

// Sortie standard
std::cout << "Message" << std::endl;

// Entrée standard
std::string input;
std::cin >> input;

// Erreur standard
std::cerr << "Error message" << std::endl;
```

#### 3. **La classe std::string**
```cpp
#include <string>

std::string str = "hello";
str = "world";                    // Pas de malloc/free !
std::cout << str << std::endl;    // Affichage direct
```

#### 4. **Algorithmes STL**
```cpp
#include <algorithm>
#include <cctype>

std::string str = "hello";
// Convertir en majuscules
std::transform(str.begin(), str.end(), str.begin(), ::toupper);
// str = "HELLO"
```

#### 5. **Ce que vous apprenez**
- ✅ Passer de C à C++ (syntaxe de base)
- ✅ Utiliser `std::cout` et `std::cin`
- ✅ Manipuler des `std::string` (adieu malloc/free!)
- ✅ Utiliser les algorithmes de la STL
- ✅ Comprendre `argc` et `argv` en C++
- ✅ Namespaces (`std::`)

---

## 📞 Exercice 01 : PhoneBook (POO Introduction)

### Concepts clés à maîtriser :

#### 1. **Structure d'une classe C++**

```cpp
class Contact {
    public:
        // Constructeur
        Contact(void);
        // Destructeur
        ~Contact(void);
        
        // Getters (accesseurs)
        std::string get_Firstname(void) const;
        
        // Setters (mutateurs)
        void set_Id(int v);
        void set_infos(void);
        
    private:
        // Attributs (données membres)
        std::string _firstname_;
        std::string _lastname_;
        std::string _nickname;
        int _id;
};
```

#### 2. **Encapsulation (public vs private)**

**Private (🔒 Caché)** :
- Attributs non accessibles depuis l'extérieur
- Protège les données internes

**Public (🔓 Accessible)** :
- Méthodes accessibles depuis l'extérieur
- Interface de la classe

```cpp
class Contact {
    private:
        std::string _firstname_;  // Pas d'accès direct
    public:
        std::string get_Firstname(void) const {
            return _firstname_;   // Accès contrôlé
        }
};
```

#### 3. **Constructeur et Destructeur**

**Constructeur** : Initialise l'objet à sa création
```cpp
Contact::Contact(void) {
    _id = 0;
    _firstname_ = "";
    std::cout << "Contact created" << std::endl;
}
```

**Destructeur** : Nettoie l'objet à sa destruction
```cpp
Contact::~Contact(void) {
    std::cout << "Contact destroyed" << std::endl;
}
```

#### 4. **Séparation header (.hpp) et implémentation (.cpp)**

**Contact_class.hpp** (Déclaration)
```cpp
#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

class Contact {
    public:
        Contact(void);
        ~Contact(void);
        std::string get_Firstname(void) const;
    private:
        std::string _firstname_;
};

#endif
```

**Contact_class.cpp** (Implémentation)
```cpp
#include "Contact_class.hpp"

Contact::Contact(void) {
    _firstname_ = "";
}

Contact::~Contact(void) {}

std::string Contact::get_Firstname(void) const {
    return _firstname_;
}
```

#### 5. **Méthodes const**
```cpp
std::string get_Firstname(void) const;
//                               ^^^^^ 
// Promet de ne pas modifier l'objet
```

- Les getters sont toujours `const`
- Permet d'appeler la méthode sur des objets `const`
- Bonne pratique de conception

#### 6. **Tableaux d'objets**
```cpp
class Phonebook {
    private:
        Contact _contacts[8];  // Tableau de 8 contacts
        int _nb_contacts;
};
```

#### 7. **Composition de classes**
```cpp
class Phonebook {
    private:
        Contact _contacts[8];  // Phonebook "a" des Contacts
};
```
- Un `Phonebook` contient des `Contact`
- Relation "has-a" (composition)

#### 8. **Gestion d'état interne**
```cpp
class Phonebook {
    private:
        int _id_contacts;    // Index du prochain contact
        int _nb_contacts;    // Nombre total de contacts
        
    public:
        void add(void);      // Modifie l'état
        void search(void);   // Lit l'état
};
```

#### 9. **Ce que vous apprenez**
- ✅ Créer des classes et objets
- ✅ Encapsulation (public/private)
- ✅ Constructeurs et destructeurs
- ✅ Getters et setters
- ✅ Méthodes const
- ✅ Composition de classes
- ✅ Organisation du code (.hpp/.cpp)
- ✅ Tableaux d'objets
- ✅ Gestion d'état dans une classe

---

## 🎓 Résumé des compétences acquises (Module 00)

### 1. **Transition C → C++**
- `printf` → `std::cout`
- `char*` → `std::string`
- Pas de `malloc/free` pour les strings

### 2. **Bases de la POO**
- Classes et objets
- Encapsulation (données privées, méthodes publiques)
- Constructeurs/Destructeurs

### 3. **Organisation du code**
- Headers guards (`#ifndef`)
- Séparation `.hpp` / `.cpp`
- Namespaces (`std::`)

### 4. **Bonnes pratiques**
- Préfixer les attributs privés (`_nom`)
- Getters en `const`
- Protéger les données (private)
- Interfaces claires (public)

---

## 📐 Conventions de nommage 42

```cpp
class ClassName {              // PascalCase pour les classes
    public:
        ClassName(void);       // Même nom que la classe
        ~ClassName(void);
        
        void methodName(void); // camelCase pour les méthodes
        int getValue(void) const;
        
    private:
        int _attributeName;    // _camelCase pour les attributs privés
        std::string _data;
};
```

---

## ⚠️ Pièges courants à éviter

1. **Oublier les headers guards** → Erreurs de redéfinition
```cpp
#ifndef CLASS_HPP
# define CLASS_HPP
// code
#endif
```

2. **Oublier `const` sur les getters**
```cpp
std::string getName(void) const;  // ✅ Correct
std::string getName(void);        // ❌ Pas const
```

3. **Attributs publics** (violation de l'encapsulation)
```cpp
class Bad {
    public:
        std::string name;  // ❌ Trop exposé
};

class Good {
    private:
        std::string _name; // ✅ Protégé
    public:
        std::string getName(void) const { return _name; }
};
```

4. **Ne pas initialiser dans le constructeur**
```cpp
// ❌ Mauvais
Contact::Contact(void) {
    // Attributs non initialisés !
}

// ✅ Bon
Contact::Contact(void) {
    _id = 0;
    _firstname_ = "";
}
```

5. **Oublier le destructeur virtuel** (pour plus tard)
```cpp
class Base {
    public:
        virtual ~Base() {}  // Important pour l'héritage
};
```

---

## 🔄 Comparaison C vs C++

| Concept | C | C++ |
|---------|---|-----|
| **Affichage** | `printf()` | `std::cout <<` |
| **Entrée** | `scanf()` | `std::cin >>` |
| **Chaînes** | `char*` + `malloc` | `std::string` |
| **Structures** | `struct` | `class` + encapsulation |
| **Organisation** | `.h` / `.c` | `.hpp` / `.cpp` |
| **Allocation** | `malloc/free` | `new/delete` |
| **Tableaux** | Taille fixe | `std::vector` (plus tard) |

---

## 💡 Concepts pour les modules suivants

Ce module pose les bases pour :
- **Module 01** : Allocation mémoire (`new`/`delete`)
- **Module 02** : Forme canonique orthodoxe
- **Module 03** : Héritage
- **Module 04** : Polymorphisme
- **Module 05-09** : Concepts avancés

---

## 📖 Ressources utiles

### Documentation C++
- [cppreference.com](https://en.cppreference.com/) : Documentation complète
- [cplusplus.com](https://cplusplus.com/) : Tutoriels et exemples

### Concepts à approfondir
- **Orthodox Canonical Form** (Module 02)
- **RAII** (Resource Acquisition Is Initialization)
- **Rule of Three/Five**
- **Const correctness**

---

## 🎯 Checklist avant de passer au Module 01

- [ ] Je comprends la différence entre C et C++
- [ ] Je sais créer une classe avec attributs et méthodes
- [ ] Je comprends public vs private
- [ ] Je sais écrire un constructeur et un destructeur
- [ ] Je sais séparer déclaration (.hpp) et implémentation (.cpp)
- [ ] Je comprends les getters/setters
- [ ] Je sais utiliser `const` correctement
- [ ] Je maîtrise `std::string` et `std::cout`
- [ ] Je comprends la composition de classes

---

**Date de création** : 12 janvier 2026  
**Module** : CPP_00 - Bases du C++ et POO
