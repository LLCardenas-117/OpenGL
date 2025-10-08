
int main(int argc, char* argv[]) {
    neu::file::SetCurrentDirectory("Assets");
    LOG_INFO("current directory {}", neu::file::GetCurrentDirectory());

    // initialize engine
    LOG_INFO("initialize engine...");
    neu::GetEngine().Initialize();

    // initialize scene


    SDL_Event e;
    bool quit = false;

    std::vector<neu::vec3> points = { {-0.5f, -0.5f, 0}, {0.5f, 0.5f, 0}, {0.5f, -0.5f, 0}, {-0.5f, 0.5f, 0} };
    std::vector<neu::vec3> colors = { {1.0f, 0, 0 }, {0, 1, 0}, {0, 0, 1}, {1, 1, 1} };

    // MAIN LOOP
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        // update
        neu::GetEngine().Update();

        if (neu::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_ESCAPE)) quit = true;

        //MAPLE WAY

        /*float angle = neu::GetEngine().GetTime().GetTime() * 90.0f;
        float scale = neu::math::Remap(-1.0f, 1.0f, 0.3f, 1.5f, neu::math::sin(neu::GetEngine().GetTime().GetTime()));
        neu::vec2 mouse = neu::GetEngine().GetInput().GetMousePosition();
        neu::vec2 position;
        position.x = neu::math::Remap(0.0f, (float)neu::GetEngine().GetRenderer().GetWidth(), -1.0f, 1.0f, mouse.x);
        position.y = -neu::math::Remap(0.0f, (float)neu::GetEngine().GetRenderer().GetHeight(), -1.0f, 1.0f, mouse.y);*/

        // LANDON WAY

        /*float mouseX = (neu::GetEngine().GetInput().GetMousePosition().x - (neu::GetEngine().GetRenderer().GetWidth() / 2)) / 610;
        float mouseY = ((neu::GetEngine().GetInput().GetMousePosition().y - (neu::GetEngine().GetRenderer().GetHeight() / 2)) / 535) * -1;
        std::cout << "Mouse X: " << mouseX << std::endl;
        std::cout << "Mouse Y: " << mouseY << std::endl;
        float angle = neu::GetEngine().GetTime().GetTime();
        float degree = 0.0f;

        if (neu::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_UP)) {
            for (auto& point : points) {
                point *= 1.1f;
            }
        }

        if (neu::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_DOWN)) {
            for (auto& point : points) {
                point *= 0.9f;
            }
        }

        if (neu::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_LEFT)) {
            angle *= -90.0f;
        }

        if (neu::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_RIGHT)) {
            angle *= 90.0f;
        }*/



        // draw
        neu::vec3 color{ 0, 0, 0 };
        neu::GetEngine().GetRenderer().SetColor(color.r, color.g, color.b);
        neu::GetEngine().GetRenderer().Clear();

        // MY WAY

        //glBegin(GL_TRIANGLES);
        //glBegin(GL_POINTS);
        //glBegin(GL_LINES);
        //glBegin(GL_LINE_STRIP);
        //glBegin(GL_QUADS);

        //for (int i = 0; i < points.size(); i++) {
        //    glColor3f(colors[i].r, colors[i].g, colors[i].b);

        //    glVertex3f((mouseX + points[i].x), (mouseY + points[i].y), points[i].z);
        //    //glVertex3f((points[i].x), (points[i].y), points[i].z);
        //}

        ////glTranslatef(mouseX, mouseY, 0);
        //glRotatef(angle, 0, 0, 1);

        // MAPLE WAY

        /*glLoadIdentity();
        glPushMatrix();

        glTranslatef(position.x, position.y, 0);
        glRotatef(angle, 0, 0, 1);
        glScalef(scale, scale, 0);

        glBegin(GL_TRIANGLES);

        for (int i = 0; i < points.size(); i++) {
            glColor3f(colors[i].r, colors[i].g, colors[i].b);
            glVertex3f(points[i].x, points[i].y, points[i].z);
        }

        glPopMatrix();*/

        glEnd();

        neu::GetEngine().GetRenderer().Present();
    }

    neu::GetEngine().Shutdown();

    return 0;
}
