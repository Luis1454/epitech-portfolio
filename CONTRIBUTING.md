# Maintenir le portfolio

Les fiches projet et le catalogue sont générés à partir de
`metadata/projects.json` :

```sh
python3 tools/portfolio.py docs
```

Une contribution doit conserver une documentation courte, une commande de
compilation vérifiable et l’absence de données personnelles. Les projets
pédagogiques restent présentés comme des archives et ne doivent pas être
présentés comme des produits de production sans validation complémentaire.

Avant de publier une modification, lancer la validation des Makefiles puis
régénérer les fiches :

```sh
python3 tools/verify_projects.py
python3 tools/portfolio.py docs
```

La validation distingue les compilations réussies, les projets bloqués par une
dépendance absente de l’environnement et les erreurs réelles du code ou du
Makefile. Le détail est conservé dans `metadata/verification.json`.
