#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "memoire.h"

// memcpy variants

void memcpy_8(void *dest_orig, const void *src_orig, size_t size)
{
    uint64_t *dest = (uint64_t *)dest_orig;
    const uint64_t *src = (const uint64_t *)src_orig;
    int i,
        max = size / sizeof(uint64_t);
    for (i = 0; i < max; i++)
        *dest++ = *src++;
}

void memcpy_4(void *dest_orig, const void *src_orig, size_t size)
{
    uint32_t *dest = (uint32_t *)dest_orig;
    const uint32_t *src = (const uint32_t *)src_orig;
    int i,
        max = size / sizeof(uint32_t);
    for (i = 0; i < max; i++)
        *dest++ = *src++;
}

void memcpy_2(void *dest_orig, const void *src_orig, size_t size)
{
    uint16_t
        *dest = (uint16_t *)dest_orig,
        *src = (uint16_t *)src_orig;
    int i,
        max = size / sizeof(uint16_t);
    for (i = 0; i < max; i++)
        *dest++ = *src++;
}

void memcpy_1(void *dest_orig, const void *src_orig, size_t size)
{
    uint8_t
        *dest = (uint8_t *)dest_orig,
        *src = (uint8_t *)src_orig;
    int i,
        max = size / sizeof(uint8_t);
    for (i = 0; i < max; i++)
        *dest++ = *src++;
}

const memcpy_t fonctions_de_copie[] = {memcpy_1, memcpy_2, memcpy_4, memcpy_8};


memcpy_t memcpy_builder(void *t, size_t elt)
{
    return fonctions_de_copie[choose_best_type_size(t, elt)];
}

int choose_best_type_size(void *v, size_t elt_size)
{
    int pointer_alignment = alignment(v),
        size = elt_size,
        res = 0;
    while (!(pointer_alignment & 1) && !(size & 1))
    {
        pointer_alignment /= 2;
        size /= 2;
        res += 1;
    }
    printf("taille choisie: %d\n", 1 << res);
    return res;
}

int alignment(void *v)
{
    if ((((uintptr_t)v) % 8) == 0)
        return 8;
    if ((((uintptr_t)v) % 4) == 0)
        return 4;
    if ((((uintptr_t)v) % 2) == 0)
        return 2;
    return 1;
}

void recopie_si_necessaire(void *t1, void *t2, size_t taille_totale, int b, memcpy_t copie)
{
    if (b)
    {
        printf("besoin de recopie\n");
        copie(t1, t2, taille_totale);
        free(t2);
    }
    else
    {
        printf("recopie inutile\n");
        free(t1);
    }
}

void swap_array(char **t1, char **t2, int *b, int *nb)
{
    char *exch;
    exch = *t1;
    *t1 = *t2;
    *t2 = exch;
    *b = !*b;
    *nb = *nb + 1;
}