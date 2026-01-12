# CPP Module 07 - Templates en C++

## 📚 Vue d'ensemble
Ce module introduit les **templates** (gabarits) en C++, permettant d'écrire du code générique réutilisable pour différents types de données.

---

## 🎯 Exercice 00 : Templates de fonctions (whatever.hpp)

### Concepts clés à maîtriser :

#### 1. **Syntaxe des templates de fonctions**
```cpp
template <typename T>
T const &max(T const &a, T const &b);
```
- `template <typename T>` : Déclaration d'un paramètre de type générique
- `T` peut être n'importe quel type (int, float, string, classe custom, etc.)
- Le compilateur génère automatiquement la fonction pour chaque type utilisé

#### 2. **Fonctions template implémentées**
- `swap(T &a, T &b)` : Échange deux valeurs
- `min(T const &a, T const &b)` : Retourne le plus petit
- `max(T const &a, T const &b)` : Retourne le plus grand

#### 3. **Points d'attention**
- Retourner par **référence constante** (`T const &`) pour éviter les copies
- Les opérateurs `<` et `>` doivent être définis pour le type T
- Le template doit être défini dans le header (pas de .cpp séparé)

#### 4. **Ce que vous apprenez**
- ✅ Écrire des fonctions génériques réutilisables
- ✅ Comprendre l'instanciation implicite des templates
- ✅ Passer des références pour optimiser les performances
- ✅ Éviter la duplication de code

---

## 🔄 Exercice 01 : Template de fonction avec itération (iter.hpp)

### Concepts clés à maîtriser :

#### 1. **Template avec plusieurs paramètres**
```cpp
template <typename T, typename F>
void iter(T *address, size_t length, F function);
```
- `T` : Type des éléments du tableau
- `F` : Type de la fonction à appliquer (peut être une fonction ou un foncteur)

#### 2. **Application d'une fonction sur un tableau**
```cpp
template <typename T, typename F>
void iter(T *address, size_t length, F function)
{
    for (size_t i = 0; i < length; i++)
        function(address[i]);
}
```

#### 3. **Flexibilité des types de fonctions**
Peut recevoir :
- Une fonction normale : `void print(int x) { std::cout << x; }`
- Un pointeur de fonction : `void (*f)(int)`
- Un foncteur (classe avec `operator()`)
- Une lambda (C++11+)

#### 4. **Ce que vous apprenez**
- ✅ Combiner plusieurs paramètres template
- ✅ Passer des fonctions en paramètres
- ✅ Créer des algorithmes génériques (style STL)
- ✅ Comprendre le concept de "higher-order functions"
- ✅ Base pour comprendre `std::for_each` et autres algorithmes STL

---

## 📦 Exercice 02 : Template de classe (Array<T>)

### Concepts clés à maîtriser :

#### 1. **Syntaxe des templates de classe**
```cpp
template <typename T>
class Array
{
    private:
        T *_array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &copy);
        ~Array();
        Array &operator=(const Array &instance);
        T &operator[](unsigned int n);
        const T &operator[](unsigned int n) const;
};
```

#### 2. **Séparation déclaration/implémentation (.hpp + .tpp)**
- **Array.hpp** : Déclaration de la classe template
- **Array.tpp** : Implémentation des méthodes
- **Important** : Include le `.tpp` à la fin du `.hpp` !

```cpp
// À la fin de Array.hpp
#include "../src/Array.tpp"
```

#### 3. **Deep copy vs Shallow copy**

**Shallow copy (❌ MAUVAIS)**
```cpp
_array = instance._array; // Copie juste le pointeur !
```

**Deep copy (✅ CORRECT)**
```cpp
delete [] _array;
_size = instance._size;
_array = new T[_size];
for (unsigned int i = 0; i < _size; i++)
    _array[i] = instance._array[i];
```

#### 4. **Gestion de la mémoire dynamique**
```cpp
// Constructeur
Array(unsigned int n) : _array(new T[n]()), _size(n) {}

// Destructeur
~Array() { delete [] _array; }

// Opérateur d'assignation
Array &operator=(const Array &instance) {
    if (this != &instance) {
        delete [] _array;           // 1. Libérer l'ancienne mémoire
        _size = instance._size;
        _array = new T[_size];      // 2. Allouer nouvelle mémoire
        // 3. Copier les éléments
    }
    return *this;
}
```

#### 5. **Surcharge de l'opérateur `[]`**
```cpp
// Version non-const (lecture/écriture)
T &operator[](unsigned int n) {
    if (n >= _size)
        throw std::out_of_range("Index out of bounds");
    return _array[n];
}

// Version const (lecture seule)
const T &operator[](unsigned int n) const {
    if (n >= _size)
        throw std::out_of_range("Index out of bounds");
    return _array[n];
}
```

#### 6. **Gestion des exceptions**
- Utiliser `throw std::out_of_range("message")` pour les accès invalides
- Inclure `<stdexcept>` si nécessaire
- Attraper avec `catch(const std::exception& e)`

#### 7. **Ce que vous apprenez**
- ✅ Créer des classes template génériques
- ✅ Implémenter la **Rule of Three** (constructeur de copie, destructeur, opérateur d'assignation)
- ✅ Gérer la mémoire dynamique correctement (éviter les fuites et double-free)
- ✅ Comprendre deep copy vs shallow copy
- ✅ Surcharger les opérateurs pour un comportement naturel
- ✅ Lancer et gérer des exceptions
- ✅ Créer des conteneurs génériques (base pour comprendre std::vector)

---

## 🎓 Résumé des compétences acquises (Module 07)

### 1. **Templates de fonctions (ex00)**
- Écrire des fonctions génériques
- Utiliser `template <typename T>`
- Optimiser avec des références constantes

### 2. **Templates avancés (ex01)**
- Combiner plusieurs types templates
- Passer des fonctions en paramètres
- Créer des algorithmes génériques

### 3. **Templates de classes (ex02)**
- Créer des conteneurs génériques
- Séparer `.hpp` et `.tpp`
- Gérer la mémoire dynamique (deep copy)
- Implémenter la Rule of Three
- Surcharger les opérateurs
- Gérer les exceptions

### 4. **Concepts C++ fondamentaux**
- **Généricité** : Un seul code pour plusieurs types
- **Type safety** : Vérification à la compilation
- **Performance** : Pas de coût à l'exécution (pas de boxing/unboxing)
- **Réutilisabilité** : Code DRY (Don't Repeat Yourself)

---

## ⚠️ Pièges courants à éviter

1. **Ne PAS compiler les .tpp séparément** → Erreur de linkage
2. **Ne PAS oublier le `delete[]`** → Fuite mémoire
3. **Vérifier `this != &instance`** dans l'opérateur d'assignation
4. **Toujours faire une deep copy** pour les pointeurs
5. **Les deux versions de `operator[]`** (const et non-const)
6. **Vérifier les bornes** avant d'accéder aux éléments

---

## 🔗 Lien avec la STL (Standard Template Library)

Ce que vous avez appris est la base de la STL :
- `swap`, `min`, `max` → `<algorithm>`
- `iter` → `std::for_each`, `std::transform`
- `Array<T>` → `std::vector<T>`, `std::array<T>`

Vous comprenez maintenant comment sont implémentés les conteneurs et algorithmes standard !

---

## 📖 Pour aller plus loin

- **Spécialisation de templates** : Comportement différent pour certains types
- **Templates variadiques** : Nombre variable de paramètres (C++11+)
- **SFINAE** : Substitution Failure Is Not An Error
- **Concepts** : Contraintes sur les types (C++20)

---

**Date de création** : 12 janvier 2026  
**Module** : CPP_07 - C++ Templates
