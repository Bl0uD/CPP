# CPP Module 01 - Gestion de la mémoire et références

## 📚 Vue d'ensemble
Ce module approfondit la gestion de la mémoire en C++, introduit les références et les pointeurs sur membres de classe. Focus sur `new`/`delete` et les différences stack vs heap.

---

## 🧟 Exercice 00 : BraiiiiiiinnnzzzZ (Zombie sur la stack et heap)

### Concepts clés à maîtriser :

#### 1. **Allocation sur la stack vs heap**

**Stack (automatique)** :
```cpp
void randomChump(std::string name) {
    Zombie zombie(name);  // Créé sur la stack
    zombie.announce();
}   // Détruit automatiquement à la fin du scope
```

**Heap (dynamique avec `new`)** :
```cpp
Zombie* newZombie(std::string name) {
    Zombie* zombie = new Zombie(name);  // Créé sur le heap
    return zombie;  // Survit après le return
}
// Doit être détruit avec delete !
```

#### 2. **Quand utiliser stack vs heap ?**

**Stack** (préférer quand possible) :
- ✅ Durée de vie courte (scope local)
- ✅ Taille connue à la compilation
- ✅ Destruction automatique
- ✅ Plus rapide

**Heap** (quand nécessaire) :
- ✅ Durée de vie au-delà du scope
- ✅ Taille inconnue ou très grande
- ❌ Gestion manuelle (`delete`)
- ❌ Plus lent, risque de fuite mémoire

#### 3. **Constructeur avec paramètres**
```cpp
class Zombie {
    public:
        Zombie(std::string name);  // Constructeur
    private:
        std::string name;
};

Zombie::Zombie(std::string name) : name(name) {}
// Liste d'initialisation ^^^
```

#### 4. **Ce que vous apprenez**
- ✅ Différence stack vs heap
- ✅ `new` et `delete`
- ✅ Durée de vie des objets
- ✅ Constructeurs avec paramètres
- ✅ Gestion de la mémoire manuelle

---

## 🧟‍♂️ Exercice 01 : Moar brainz! (Tableau dynamique)

### Concepts clés à maîtriser :

#### 1. **Allocation de tableaux avec `new[]`**
```cpp
Zombie* zombieHorde(int N, std::string name) {
    Zombie* horde = new Zombie[N];  // Tableau dynamique
    
    for (int i = 0; i < N; i++) {
        // Initialiser chaque zombie
    }
    return horde;
}
```

#### 2. **Libération avec `delete[]`**
```cpp
Zombie* horde = zombieHorde(5, "Bob");
// Utilisation...
delete[] horde;  // ⚠️ delete[] pour les tableaux !
//      ^^ Ne pas oublier les crochets !
```

#### 3. **Constructeur par défaut obligatoire**
```cpp
class Zombie {
    public:
        Zombie();           // Nécessaire pour new Zombie[N]
        Zombie(std::string name);
        void setName(std::string name);
};
```

#### 4. **Ce que vous apprenez**
- ✅ Allocation de tableaux dynamiques (`new[]`)
- ✅ Libération correcte (`delete[]`)
- ✅ Constructeur par défaut
- ✅ Initialisation post-construction

---

## 🧠 Exercice 02 : HI THIS IS BRAIN (Pointeurs et références)

### Concepts clés à maîtriser :

#### 1. **Pointeur vs Référence**

**Pointeur** :
```cpp
std::string str = "HI THIS IS BRAIN";
std::string* stringPTR = &str;  // Pointeur

std::cout << *stringPTR;  // Déréférencement
stringPTR = nullptr;      // Peut être réassigné
```

**Référence** :
```cpp
std::string str = "HI THIS IS BRAIN";
std::string& stringREF = str;  // Référence (alias)

std::cout << stringREF;   // Pas de déréférencement
// stringREF = autre;     // ❌ Ne peut pas être réassignée
```

#### 2. **Comparaison Pointeur vs Référence**

| Caractéristique | Pointeur | Référence |
|----------------|----------|-----------|
| **Syntaxe** | `Type*` | `Type&` |
| **Déréférencement** | Explicite (`*ptr`) | Implicite |
| **Peut être NULL** | ✅ Oui | ❌ Non |
| **Réassignable** | ✅ Oui | ❌ Non |
| **Usage** | Quand optionnel | Quand obligatoire |

#### 3. **Quand utiliser quoi ?**

**Utiliser une référence** :
- Paramètres de fonction (éviter copie)
- Retour de fonction (pas de copie)
- Alias obligatoire

**Utiliser un pointeur** :
- Peut être NULL/nullptr
- Besoin de réassigner
- Tableaux dynamiques

#### 4. **Ce que vous apprenez**
- ✅ Différence pointeur vs référence
- ✅ Adresses mémoire (`&variable`)
- ✅ Déréférencement (`*ptr`)
- ✅ Alias avec références
- ✅ Quand utiliser l'un ou l'autre

---

## ⚔️ Exercice 03 : Unnecessary violence (Références dans les classes)

### Concepts clés à maîtriser :

#### 1. **Référence comme attribut de classe**
```cpp
class HumanA {
    private:
        Weapon& _weapon;  // Référence (toujours valide)
    public:
        HumanA(std::string name, Weapon& weapon) 
            : _name(name), _weapon(weapon) {}  // Initialisation obligatoire
};
```

#### 2. **Pointeur comme attribut de classe**
```cpp
class HumanB {
    private:
        Weapon* _weapon;  // Pointeur (peut être NULL)
    public:
        HumanB(std::string name) : _name(name), _weapon(nullptr) {}
        
        void setWeapon(Weapon& weapon) {
            _weapon = &weapon;
        }
};
```

#### 3. **Liste d'initialisation obligatoire pour références**
```cpp
// ✅ Correct
HumanA::HumanA(std::string name, Weapon& weapon)
    : _name(name), _weapon(weapon) {}

// ❌ Erreur - référence non initialisée
HumanA::HumanA(std::string name, Weapon& weapon) {
    _weapon = weapon;  // Trop tard !
}
```

#### 4. **Référence const pour les getters**
```cpp
class Weapon {
    public:
        const std::string& getType() const;
        //    ^^^^^^ Retourne référence const
        //                             ^^^^^ Méthode const
};
```

#### 5. **Ce que vous apprenez**
- ✅ Références comme membres de classe
- ✅ Liste d'initialisation obligatoire
- ✅ Différence de design (référence vs pointeur)
- ✅ Retourner des références const
- ✅ Choisir entre référence et pointeur selon le besoin

---

## 📝 Exercice 04 : Sed is for losers (Manipulation de fichiers)

### Concepts clés à maîtriser :

#### 1. **Flux de fichiers (fstream)**
```cpp
#include <fstream>

// Lecture
std::ifstream infile("filename");
if (!infile.is_open()) {
    std::cerr << "Error opening file" << std::endl;
    return;
}

// Écriture
std::ofstream outfile("filename.replace");
```

#### 2. **Lecture ligne par ligne**
```cpp
std::string line;
while (std::getline(infile, line)) {
    // Traiter chaque ligne
}
```

#### 3. **Recherche et remplacement de chaînes**
```cpp
std::string replaceLine(std::string line, std::string s1, std::string s2) {
    size_t pos = 0;
    while ((pos = line.find(s1, pos)) != std::string::npos) {
        line.erase(pos, s1.length());
        line.insert(pos, s2);
        pos += s2.length();
    }
    return line;
}
```

#### 4. **Ce que vous apprenez**
- ✅ Manipulation de fichiers (ifstream/ofstream)
- ✅ Vérification d'ouverture
- ✅ Lecture avec `std::getline`
- ✅ Méthodes de std::string (find, erase, insert)
- ✅ Gestion d'erreurs

---

## 🗣️ Exercice 05-06 : Harl (Pointeurs sur fonctions membres)

### Concepts clés à maîtriser :

#### 1. **Pointeurs sur fonctions membres**
```cpp
class Harl {
    private:
        void debug(void) const;
        void info(void) const;
        void warning(void) const;
        void error(void) const;
    public:
        void complain(std::string level);
};
```

#### 2. **Tableau de pointeurs sur méthodes**
```cpp
void Harl::complain(std::string level) {
    // Déclaration du type
    void (Harl::*functions[])(void) const = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*functions[i])();  // Appel via pointeur
            return;
        }
    }
}
```

#### 3. **Syntaxe des pointeurs sur membres**
```cpp
// Déclaration
void (Harl::*ptr)(void) const;

// Assignation
ptr = &Harl::debug;

// Appel
(this->*ptr)();
//      ^ Opérateur de déréférencement pour membre
```

#### 4. **Switch avec fall-through (ex06)**
```cpp
switch (level) {
    case DEBUG:
        debug();
        // Fall through
    case INFO:
        info();
        // Fall through
    case WARNING:
        warning();
        // Fall through
    case ERROR:
        error();
        break;
    default:
        std::cout << "Unknown level" << std::endl;
}
```

#### 5. **Ce que vous apprenez**
- ✅ Pointeurs sur fonctions membres
- ✅ Tableaux de pointeurs de fonctions
- ✅ Éviter les `if/else` en cascade
- ✅ Switch avec fall-through
- ✅ Design patterns (Strategy pattern)

---

## 🎓 Résumé des compétences acquises (Module 01)

### 1. **Gestion mémoire**
- Stack vs Heap
- `new` / `delete`
- `new[]` / `delete[]`
- Fuites mémoire

### 2. **Pointeurs et références**
- Différences et usages
- Références comme membres
- Pointeurs sur fonctions membres

### 3. **Manipulation de données**
- Fichiers (ifstream/ofstream)
- std::string avancé
- Recherche et remplacement

### 4. **Design**
- Choisir stack vs heap
- Choisir référence vs pointeur
- Tableaux de pointeurs de fonctions

---

## ⚠️ Pièges courants à éviter

1. **Oublier `delete`** → Fuite mémoire
```cpp
Zombie* z = new Zombie("Bob");
// ... utilisation ...
delete z;  // ⚠️ Ne pas oublier !
```

2. **Confondre `delete` et `delete[]`**
```cpp
Zombie* horde = new Zombie[5];
delete[] horde;  // ✅ Correct
delete horde;    // ❌ Comportement indéfini !
```

3. **Référence non initialisée**
```cpp
class Bad {
    Weapon& weapon;  // ❌ Doit être initialisée dans le constructeur
};
```

4. **Pointeur dangling**
```cpp
Zombie* getZombie() {
    Zombie z("Bob");  // Sur la stack
    return &z;        // ❌ Détruit à la fin de la fonction !
}
```

5. **Fichier non fermé**
```cpp
std::ifstream file("data.txt");
// ... utilisation ...
file.close();  // Optionnel (fermé automatiquement) mais bonne pratique
```

---

## 🔄 Comparaison C vs C++ (Mémoire)

| C | C++ |
|---|-----|
| `malloc()` | `new` |
| `free()` | `delete` |
| `calloc()` | `new[]` |
| Pas de constructeur | Constructeur appelé |
| Pas de destructeur | Destructeur appelé |
| Retourne `void*` | Retourne le type correct |

---

## 📖 Pour aller plus loin

- **RAII** : Resource Acquisition Is Initialization
- **Smart pointers** (C++11) : `std::unique_ptr`, `std::shared_ptr`
- **Move semantics** (C++11)
- **Rule of Three** (Module 02)

---

**Date de création** : 12 janvier 2026  
**Module** : CPP_01 - Gestion mémoire et références
