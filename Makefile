# Define the main executable
TARGET = tes

# Define the source code files
SOURCES = main.cpp toko/Toko.cpp peran/Peran.cpp peran/Petani.cpp peran/Peternak.cpp peran/Walikota.cpp Pcolor/pcolor.c Item/Item.cpp Item/Bangunan/Bangunan.cpp Item/Hewan/Carnivore.cpp Item/Hewan/Herbivore.cpp Item/Hewan/Omnivore.cpp Item/Hewan/Hewan.cpp Item/Produk/Produk.cpp Item/Tanaman/Tanaman.cpp input/Konfigurasi_Animal.cpp input/Konfigurasi_Tanaman.cpp input/Konfigurasi_Produk.cpp input/Konfigurasi_Recipe.cpp input/Konfigurasi_Item.cpp grandmaster/Grandmaster.cpp

# Define the compiler and flags
CC = g++
CFLAGS = -o $(TARGET) -Wall

# Define the all rule
run: all
	@./tes

all: $(TARGET)

# Define the $(TARGET) rule
$(TARGET): $(SOURCES)
	@$(CC) $(CFLAGS) $(SOURCES)

# Define the clean rule
clean:
	@rm $(TARGET)
