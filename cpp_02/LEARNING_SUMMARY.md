# CPP Module 02 - Forme Canonique Orthodoxe et Nombres à virgule fixe

## 📚 Vue d'ensemble
Ce module introduit la **forme canonique orthodoxe** (Orthodox Canonical Form) et implémente une classe de nombres à virgule fixe. Focus sur les surcharges d'opérateurs et la gestion correcte de la copie.

---

## 🔢 Exercice 00 : Ma première classe en forme canonique orthodoxe

### Concepts clés à maîtriser :

#### 1. **La Forme Canonique Orthodoxe (Orthodox Canonical Form)**

Une classe doit **toujours** implémenter ces 4 éléments :

```cpp
class Fixed {
    public:
        Fixed();                              // 1. Constructeur par défaut
        Fixed(const Fixed& other);            // 2. Constructeur de copie
        Fixed& operator=(const Fixed& other); // 3. Opérateur d'assignation
        ~Fixed();                             // 4. Destructeur
};
```

#### 2. **Pourquoi la forme canonique ?**

Sans elle, le compilateur génère des versions par défaut qui font des **copies superficielles** (shallow copy), ce qui pose problème avec :
- Pointeurs
- Ressources (fichiers, mémoire, etc.)
- Attributs nécessitant une gestion spéciale

#### 3. **Implémentation du constructeur de copie**
```cpp
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;  // Utilise l'opérateur d'assignation
    // OU
    this->_fixedPoint = other.getRawBits();
}
```

#### 4. **Implémentation de l'opérateur d'assignation**
```cpp
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {  // Protection contre auto-assignation
        this->_fixedPoint = other.getRawBits();
    }
    return *this;  // Retourne *this pour chaînage (a = b = c)
}
```

#### 5. **Nombre à virgule fixe (Fixed-point)**

**Concept** :
- Stocke un nombre décimal dans un `int`
- Utilise des bits pour la partie fractionnaire
- Plus rapide que `float` (pas de FPU nécessaire)

**Représentation** :
```cpp
class Fixed {
    private:
        int _fixedPoint;           // Valeur brute
        static const int _bits = 8; // Nombre de bits fractionnaires
};

// Exemple : 42.42 en virgule fixe avec 8 bits fractionnaires
// 42.42 * 256 = 10859 (stocké dans _fixedPoint)
```

#### 6. **Ce que vous apprenez**
- ✅ **Rule of Three** (Destructeur, Copy Constructor, Copy Assignment)
- ✅ Protection contre l'auto-assignation
- ✅ Retourner `*this` dans les opérateurs
- ✅ Membres statiques const
- ✅ Nombres à virgule fixe

---

## 🔄 Exercice 01 : Vers une classe plus utile

### Concepts clés à maîtriser :

#### 1. **Constructeurs de conversion**
```cpp
class Fixed {
    public:
        Fixed(const int value);      // Convertit int → Fixed
        Fixed(const float value);    // Convertit float → Fixed
        
        int toInt(void) const;       // Convertit Fixed → int
        float toFloat(void) const;   // Convertit Fixed → float
};
```

#### 2. **Conversion int → Fixed**
```cpp
Fixed::Fixed(const int value) {
    // Décale de _bits positions vers la gauche
    _fixedPoint = value << _bits;
    // Exemple : 42 << 8 = 10752
}
```

#### 3. **Conversion float → Fixed**
```cpp
Fixed::Fixed(const float value) {
    // Multiplie par 2^_bits et arrondit
    _fixedPoint = roundf(value * (1 << _bits));
    // Exemple : 42.42 * 256 = 10859.52 → 10860
}
```

#### 4. **Conversion Fixed → int**
```cpp
int Fixed::toInt(void) const {
    // Décale de _bits positions vers la droite
    return _fixedPoint >> _bits;
    // Exemple : 10860 >> 8 = 42
}
```

#### 5. **Conversion Fixed → float**
```cpp
float Fixed::toFloat(void) const {
    // Divise par 2^_bits
    return (float)_fixedPoint / (1 << _bits);
    // Exemple : 10860 / 256 = 42.421875
}
```

#### 6. **Surcharge de l'opérateur `<<`**
```cpp
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

// Usage :
Fixed a(42.42f);
std::cout << a << std::endl;  // Affiche : 42.42
```

**Important** : Fonction **friend** ou fonction **globale** (pas méthode de classe)

#### 7. **Ce que vous apprenez**
- ✅ Constructeurs de conversion
- ✅ Conversions entre types
- ✅ Décalages binaires (`<<`, `>>`)
- ✅ Surcharge de `operator<<` pour `std::cout`
- ✅ Manipulation de bits
- ✅ Arrondi avec `roundf()`

---

## 🧮 Exercice 02 : Maintenant on parle !

### Concepts clés à maîtriser :

#### 1. **Opérateurs de comparaison**
```cpp
class Fixed {
    public:
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
};

// Implémentation
bool Fixed::operator>(const Fixed& other) const {
    return this->_fixedPoint > other._fixedPoint;
}
```

#### 2. **Opérateurs arithmétiques**
```cpp
class Fixed {
    public:
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
};

// Addition
Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

// Multiplication (attention au décalage!)
Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}
```

#### 3. **Opérateurs d'incrémentation/décrémentation**

**Pré-incrémentation** (`++a`) :
```cpp
Fixed& Fixed::operator++() {  // Retourne une référence
    _fixedPoint++;
    return *this;
}
```

**Post-incrémentation** (`a++`) :
```cpp
Fixed Fixed::operator++(int) {  // Paramètre int fictif
    Fixed temp(*this);  // Copie l'état actuel
    _fixedPoint++;
    return temp;        // Retourne l'ancienne valeur
}
```

**Différence** :
```cpp
Fixed a(5);
Fixed b = ++a;  // a = 6, b = 6 (pré-incrémentation)
Fixed c = a++;  // a = 7, c = 6 (post-incrémentation)
```

#### 4. **Fonctions statiques min/max**
```cpp
class Fixed {
    public:
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}
```

#### 5. **Tableau récapitulatif des opérateurs**

| Catégorie | Opérateurs | Retour |
|-----------|------------|--------|
| **Comparaison** | `>`, `<`, `>=`, `<=`, `==`, `!=` | `bool` |
| **Arithmétique** | `+`, `-`, `*`, `/` | `Fixed` |
| **Pré-incr/décr** | `++a`, `--a` | `Fixed&` |
| **Post-incr/décr** | `a++`, `a--` | `Fixed` |
| **Min/Max** | `min()`, `max()` | `Fixed&` |

#### 6. **Ce que vous apprenez**
- ✅ Surcharge complète des opérateurs
- ✅ Différence pré/post incrémentation
- ✅ Fonctions statiques
- ✅ Surcharge avec const
- ✅ Opérateurs de comparaison
- ✅ Opérateurs arithmétiques

---

## 🎓 Résumé des compétences acquises (Module 02)

### 1. **Forme Canonique Orthodoxe**
- Constructeur par défaut
- Constructeur de copie
- Opérateur d'assignation
- Destructeur
- Protection auto-assignation

### 2. **Surcharge d'opérateurs**
- Opérateurs de comparaison
- Opérateurs arithmétiques
- Incrémentation/Décrémentation
- Opérateur d'insertion (`<<`)

### 3. **Nombres à virgule fixe**
- Représentation binaire
- Conversions int/float
- Décalages binaires
- Arithmétique en virgule fixe

### 4. **Concepts avancés**
- Fonctions statiques
- Membres const
- Retour par référence
- Surcharge avec const

---

## ⚠️ Pièges courants à éviter

1. **Oublier la protection contre l'auto-assignation**
```cpp
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {  // ⚠️ Toujours vérifier !
        // ...
    }
    return *this;
}
```

2. **Retourner une référence locale**
```cpp
// ❌ ERREUR
Fixed& Fixed::operator+(const Fixed& other) const {
    Fixed result;
    return result;  // Référence vers objet local détruit !
}

// ✅ CORRECT
Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(...);  // Retourne par valeur
}
```

3. **Confondre pré et post incrémentation**
```cpp
Fixed& operator++();     // Pré : retourne référence
Fixed operator++(int);   // Post : retourne copie
```

4. **Multiplication en virgule fixe**
```cpp
// ❌ Erreur (double décalage)
Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->_fixedPoint * other._fixedPoint);
}

// ✅ Correct
Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}
```

5. **Oublier `const` sur les getters**
```cpp
int getRawBits(void) const;  // ✅
int getRawBits(void);         // ❌ Pas const
```

---

## 📊 Virgule fixe vs Virgule flottante

| Caractéristique | Fixed-point | Float |
|----------------|-------------|-------|
| **Précision** | Fixe | Variable |
| **Vitesse** | Rapide | Plus lent |
| **Mémoire** | Moins | Plus |
| **Range** | Limité | Grand |
| **Usage** | Embedded, Finance | Scientifique |

---

## 🔢 Exemples de calculs en virgule fixe

**Avec 8 bits fractionnaires** :

```
Nombre réel : 42.42
Virgule fixe : 42.42 × 2^8 = 42.42 × 256 = 10859.52 ≈ 10860
Stocké : 10860

Reconversion :
10860 ÷ 256 = 42.421875
```

---

## 📖 Pour aller plus loin

- **Rule of Five** (C++11) : + Move constructor + Move assignment
- **Surcharge d'opérateurs avancée** : `()`, `[]`, `->`
- **Conversion explicite/implicite** : `explicit` keyword
- **Copy elision** et **RVO** (Return Value Optimization)

---

**Date de création** : 12 janvier 2026  
**Module** : CPP_02 - Forme Canonique et Surcharge d'opérateurs
