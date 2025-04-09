# Используем базовый образ с GCC и CMake
FROM gcc:14.2.0

# Устанавливаем необходимые зависимости: cmake, gtest, gdb, latex
RUN apt-get update && apt-get install -y \
    cmake \
    libgtest-dev \
    gdb \
    texlive-latex-base \
    texlive-lang-cyrillic \
    texlive-latex-recommended \
    texlive-latex-extra \
    && rm -rf /var/lib/apt/lists/*

# Устанавливаем рабочую директорию
WORKDIR /workspace