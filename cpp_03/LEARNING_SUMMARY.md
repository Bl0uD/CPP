# CPP Module 03 - Héritage

## 📚 Vue d'ensemble
Ce module introduit l'**héritage** en C++, permettant de créer des hiérarchies de classes. Focus sur la réutilisation de code et les relations "is-a".

---

## 🤖 Exercice 00 : Aaaaand... OPEN! (Classe de base)

### Concepts clés à maîtriser :

#### 1. **Classe de base simple**
```cpp
class ClapTrap {
    private:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
        
    public:
        ClapTrap(std::string name);
        ~ClapTrap();
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
```

#### 2. **Logique métier**
```cpp
void ClapTrap::attack(const std::string& target) {
    if (_energyPoints <= 0 || _hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " can't attack!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" 
              << std::endl;
}
```

#### 3. **Gestion d'état**
- Points de vie (HP)
- Points d'énergie (EP)
- Dégâts d'attaque
- Vérification de validité avant action

#### 4. **Ce que vous apprenez**
- ✅ Classe de base complète
- ✅ Gestion d'état interne
- ✅ Validation des actions
- ✅ Messages informatifs
- ✅ Forme canonique orthodoxe

---

## 🏰 Exercice 01 : Serena, my love! (Héritage simple)

### Concepts clés à maîtriser :

#### 1. **Syntaxe de l'héritage**
```cpp
class ScavTrap : public ClapTrap {
    //              ^^^^^^ Type d'héritage
    public:
        ScavTrap(std::string name);
        ~ScavTrap();
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);
        
        void attack(const std::string& target); // Surcharge
        void guardGate();                        // Nouvelle méthode
};
```

#### 2. **Appel du constructeur de base**
```cpp
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
//                                     ^^^^^^^^^^^^^^^^^
//                                     Appelle le constructeur parent
    std::cout << "ScavTrap constructor called" << std::endl;
    _hitPoints = 100;      // Valeurs spécifiques à ScavTrap
    _energyPoints = 50;
    _attackDamage = 20;
}
```

#### 3. **Ordre d'appel des constructeurs/destructeurs**

**Construction** :
```
1. ClapTrap constructor
2. ScavTrap constructor
```

**Destruction** :
```
1. ScavTrap destructor
2. ClapTrap destructor
```

#### 4. **Modificateur d'accès `protected`**
```cpp
class ClapTrap {
    protected:  // Accessible dans les classes dérivées
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
        
    public:
        // ...
};
```

| Modificateur | Classe | Dérivées | Extérieur |
|--------------|--------|----------|-----------|
| `private` | ✅ | ❌ | ❌ |
| `protected` | ✅ | ✅ | ❌ |
| `public` | ✅ | ✅ | ✅ |

#### 5. **Surcharge de méthodes**
```cpp
// Dans ClapTrap
void ClapTrap::attack(const std::string& target) {
    std::cout << "ClapTrap attacks!" << std::endl;
}

// Dans ScavTrap (surcharge)
void ScavTrap::attack(const std::string& target) {
    std::cout << "ScavTrap attacks!" << std::endl;
    // Comportement différent
}
```

#### 6. **Ce que vous apprenez**
- ✅ Syntaxe de l'héritage
- ✅ Modificateur `protected`
- ✅ Appel du constructeur parent
- ✅ Ordre de construction/destruction
- ✅ Surcharge de méthodes
- ✅ Relation "is-a"

---

## 💎 Exercice 02 : Repetitive work (Héritage multiple)

### Concepts clés à maîtriser :

#### 1. **Hiérarchie d'héritage**
```
        ClapTrap (base)
           /    \
          /      \
    ScavTrap    FragTrap
```

```cpp
class FragTrap : public ClapTrap {
    public:
        FragTrap(std::string name);
        ~FragTrap();
        
        void highFivesGuys(void);  // Méthode spécifique
};
```

#### 2. **Valeurs différentes par classe**

| Classe | HP | EP | ATK |
|--------|----|----|-----|
| ClapTrap | 10 | 10 | 0 |
| ScavTrap | 100 | 50 | 20 |
| FragTrap | 100 | 100 | 30 |

```cpp
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}
```

#### 3. **Méthodes spécifiques à chaque classe**
```cpp
// ScavTrap uniquement
void ScavTrap::guardGate() {
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

// FragTrap uniquement
void FragTrap::highFivesGuys() {
    std::cout << "FragTrap requests a high five!" << std::endl;
}
```

#### 4. **Constructeur de copie avec héritage**
```cpp
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
//                                          ^^^^^^^^^^^^^^^^^
//                                          Copie la partie ClapTrap
    std::cout << "ScavTrap copy constructor" << std::endl;
    *this = other;
}
```

#### 5. **Opérateur d'assignation avec héritage**
```cpp
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);  // Appelle l'opérateur du parent
        // Copie des attributs spécifiques si nécessaire
    }
    return *this;
}
```

#### 6. **Ce que vous apprenez**
- ✅ Hiérarchie de classes
- ✅ Plusieurs classes dérivées
- ✅ Spécialisation de comportement
- ✅ Forme canonique avec héritage
- ✅ Réutilisation de code

---

## 🎓 Résumé des compétences acquises (Module 03)

### 1. **Héritage**
- Syntaxe `class Derived : public Base`
- Relation "is-a"
- Constructeurs avec héritage
- Destructeurs avec héritage

### 2. **Modificateurs d'accès**
- `private` : Classe uniquement
- `protected` : Classe + dérivées
- `public` : Tout le monde

### 3. **Forme canonique avec héritage**
- Appel des constructeurs parents
- Copie de la partie parent
- Opérateur d'assignation du parent

### 4. **Design**
- Hiérarchie de classes
- Spécialisation
- Réutilisation de code
- Éviter la duplication

---

## ⚠️ Pièges courants à éviter

1. **Oublier d'appeler le constructeur parent**
```cpp
// ❌ Erreur
ScavTrap::ScavTrap(std::string name) {
    _name = name;  // Attribut non initialisé correctement
}

// ✅ Correct
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    // Initialisation spécifique
}
```

2. **Attributs privés inaccessibles dans dérivées**
```cpp
class ClapTrap {
    private:
        std::string _name;  // ❌ Inaccessible dans ScavTrap
};

class ClapTrap {
    protected:
        std::string _name;  // ✅ Accessible dans ScavTrap
};
```

3. **Oublier d'appeler l'opérateur parent**
```cpp
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);  // ⚠️ Ne pas oublier !
    }
    return *this;
}
```

4. **Destructeur non virtuel** (pour plus tard)
```cpp
class ClapTrap {
    public:
        virtual ~ClapTrap();  // Important avec héritage
};
```

5. **Constructeur de copie incomplet**
```cpp
// ❌ Erreur
ScavTrap::ScavTrap(const ScavTrap& other) {
    *this = other;  // Parent non copié !
}

// ✅ Correct
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    *this = other;
}
```

---

## 🏗️ Types d'héritage en C++

```cpp
class Derived : public Base {};     // Public (le plus courant)
class Derived : protected Base {};  // Protected
class Derived : private Base {};    // Private
```

| Héritage | public → | protected → | private → |
|----------|----------|-------------|-----------|
| **public** | public | protected | private |
| **protected** | protected | protected | private |
| **private** | private | private | private |

**Recommandation** : Toujours utiliser `public` à 42 (et en général).

---

## 📊 Comparaison Composition vs Héritage

**Héritage** (is-a) :
```cpp
class ScavTrap : public ClapTrap {
    // ScavTrap EST UN ClapTrap
};
```

**Composition** (has-a) :
```cpp
class Robot {
    private:
        ClapTrap _claptrap;  // Robot A UN ClapTrap
};
```

**Préférer la composition** sauf si vraie relation "is-a".

---

## 🔄 Ordre d'exécution complet

```cpp
ScavTrap scav("Bob");
// 1. ClapTrap::ClapTrap("Bob")
// 2. ScavTrap::ScavTrap("Bob")

scav.attack("target");
// 3. ScavTrap::attack() (surcharge)

// Fin de scope
// 4. ScavTrap::~ScavTrap()
// 5. ClapTrap::~ClapTrap()
```

---

## 💡 Concepts pour le module suivant

Ce module prépare pour :
- **Module 04** : Polymorphisme et méthodes virtuelles
- **virtual** et **override**
- Classes abstraites
- Destructeur virtuel

---

## 📖 Pour aller plus loin

- **Héritage multiple** (diamant problem)
- **Virtual inheritance**
- **Interface (classes abstraites pures)**
- **SOLID principles** (Liskov Substitution Principle)

---

**Date de création** : 12 janvier 2026  
**Module** : CPP_03 - Héritage
