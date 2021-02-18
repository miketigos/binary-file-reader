#include <stdio.h>
#include <string.h>

struct record
{
    float lat;
    float lon;
    short alt;
    char name[5];
    char misc;
};

int main()
{
    FILE *binFile;
    struct record rec;
    binFile = fopen("tracks_copy.dat", "rb");
    while ((fread(&rec, sizeof(struct record), 1, binFile)) == 1)
    {
        char id_val = rec.misc & 3;
        char* id = "xx";
        if (id_val == 0)
            id = "unknown";
        else if (id_val == 1)
            id = "friend";
        else if (id_val == 2)
            id = "foe";
        else if (id_val == 3)
            id = "neutral";

        char cat_val = (rec.misc >> 2) & 3;
        char* cat = "xx";
        if (cat_val == 0)
            cat = "ship";
        else if (cat_val == 1)
            cat = "ground vehicle";
        else if (cat_val == 2)
            cat = "airplane";

        char eng_val = (rec.misc >> 4) & 1;
        char* eng = "xx";
        if (eng_val == 0)
            eng = "not engaged";
        else if (eng_val == 1)
            eng = "engaged";

        char new_name[6]; 
        strcpy(new_name, rec.name);
        new_name[6] = '\0';
        printf("Lat: %f, Lon: %f, Alt: %i,\n Name: %s, Id: %s Cat: %s, Eng: %s\n",
                rec.lat, rec.lon, rec.alt, new_name, id, cat, eng);
    }
}