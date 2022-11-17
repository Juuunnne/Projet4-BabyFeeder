// #include "./hpp/Shoppinglist.hpp"

// Shoppinglist::Shoppinglist()
// {
//     Product panier;
//     textTexture = NULL;
//     tWidth = 0;
//     tHeight = 0;
//     textFont = TTF_OpenFont("./OpenSans-Bold.ttf", 20);

//     if (textFont == NULL)
//     {
//         printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
//     }
//     else
//         SDL_Color textColor = {0, 0, 0, 0xFF};
// }

// Shoppinglist::~Shoppinglist()
// {
// }

// int Shoppinglist::getWidth()
// {
//     return tWidth;
// }

// int Shoppinglist::getHeight()
// {
//     return tHeight;
// }

// void Shoppinglist::setColor(Uint8 red, Uint8 green, Uint8 blue)
// {
//     // Modulate texture rgb
//     SDL_SetTextureColorMod(textTexture, red, green, blue);
// }

// void Shoppinglist::setBlendMode(SDL_BlendMode blending)
// {
//     // Set blending function
//     SDL_SetTextureBlendMode(textTexture, blending);
// }

// bool Shoppinglist::loadFromRenderedText(string textureText, SDL_Color textColor, SDL_Renderer *renderer)
// {
//     // Get rid of preexisting texture
//     free();

//     // Render text surface
//     SDL_Surface *textSurface = TTF_RenderText_Blended(textFont, textureText.c_str(), textColor);
//     if (textSurface != NULL)
//     {
//         // Create texture from surface pixels
//         textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
//         if (textTexture == NULL)
//         {
//             printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
//         }
//         else
//         {
//             // Get image dimensions
//             tWidth = textSurface->w;
//             tHeight = textSurface->h;
//         }

//         // Get rid of old surface
//         SDL_FreeSurface(textSurface);
//     }
//     else
//     {
//         printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
//     }

//     // Return success
//     return textTexture != NULL;
// }

// bool Shoppinglist::loadShoplist(vector<Product> shop_list, SDL_Color textColor, SDL_Renderer *renderer)
// {
//     // Get rid of preexisting texture
//     free();

//     // Render text surface
//     for (Product p : shop_list)
//     {
//         SDL_Surface *textSurface = TTF_RenderText_Blended(textFont, p.product_name.c_str(), textColor);
//         if (textSurface != NULL)
//         {
//             // Create texture from surface pixels
//             textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
//             if (textTexture == NULL)
//             {
//                 printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
//             }
//             else
//             {
//                 // Get image dimensions
//                 tWidth = textSurface->w;
//                 tHeight = textSurface->h;
//             }

//             // Get rid of old surface
//             SDL_FreeSurface(textSurface);
//         }
//         else
//         {
//             printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
//         }
//     }

//     // Return success
//     return textTexture != NULL;
// }

// void Shoppinglist::free()
// {
//     // Free texture if it exists
//     if (textTexture != NULL)
//     {
//         SDL_DestroyTexture(textTexture);
//         textTexture = NULL;
//         tWidth = 0;
//         tHeight = 0;
//     }
// }

// void Shoppinglist::handleEvent(SDL_Event e, SDL_Renderer *renderer)
// {
//     // Special key input
//     if (e.type == SDL_KEYDOWN)
//     {
//         // Handle backspace
//         if (e.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0)
//         {
//             // lop off character
//             inputText.pop_back();
//             renderText = true;
//         }
//         // Handle copy
//         if (e.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL)
//         {
//             SDL_SetClipboardText(inputText.c_str());
//         }
//         // Handle paste
//         if (e.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL)
//         {
//             inputText = SDL_GetClipboardText();
//             renderText = true;
//         }
//         if (e.key.keysym.sym == SDLK_RETURN)
//         {
//             addToList();

//             cout << "Enter Pressed" << endl;
//         }
//     }
//     // Special text input event
//     else if (e.type == SDL_TEXTINPUT)
//     {
//         // Not copy or pasting
//         if (!(SDL_GetModState() & KMOD_CTRL && (e.text.text[0] == 'c' || e.text.text[0] == 'C' || e.text.text[0] == 'v' || e.text.text[0] == 'V')))
//         {
//             // Append character
//             inputText += e.text.text;
//             renderText = true;
//         }
//     }

//     if (renderText)
//     {
//         // Text is not empty
//         if (inputText != "")
//         {
//             // Render new text
//             loadFromRenderedText(inputText.c_str(), textColor, renderer);
//         }
//         // Text is empty
//         else
//         {
//             // Render space texture
//             loadFromRenderedText(" ", textColor, renderer);
//         }
//     }
// }

// void Shoppinglist::render(SDL_Renderer *renderer, int x, int y, SDL_Rect *clip, double angle, SDL_Point *center, SDL_RendererFlip flip)
// {
//     // Set rendering space and render to screen
//     SDL_Rect renderQuad = {x, y, tWidth, tHeight};

//     // Set clip rendering dimensions
//     if (clip != NULL)
//     {
//         renderQuad.w = clip->w;
//         renderQuad.h = clip->h;
//     }
//     SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
//     // Render to screen
//     SDL_RenderCopyEx(renderer, textTexture, clip, &renderQuad, angle, center, flip);
// }

// void Shoppinglist::addToList()
// {
//     panier.product_name = inputText;
//     panier.product_number = 2;
//     shop_list.push_back(panier);
//     inputText.clear();
//     // Check if add to list
//     for (int i = 0; i < shop_list.size(); i++)
//     {
//         cout << "There are : " << shop_list[i].product_name << endl;
//         cout << "Need" << shop_list[i].product_number << endl;
//     }
// }

// vector<Product> Shoppinglist::getShoppinglist()
// {
//     return this->shop_list;
// }

