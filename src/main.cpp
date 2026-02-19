//
// Created by vovaz on 02.12.2025.
//
#include <vector>

#include "raylib.h"

#include "zem/physics/physics_world.h"

int main() {
  // 1. Инициализация окна (800x600)
    InitWindow(1280, 720, "ZEM Physics Engine - DOD Demo");
    SetTargetFPS(60); // Лочим на 60 FPS

    // 2. Настройка 3D камеры
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f }; // Стоим сбоку и сверху
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Смотрим в центр (0,0,0)
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Где "верх"
    camera.fovy = 45.0f;                                // Угол обзора
    camera.projection = CAMERA_PERSPECTIVE;

    // 3. Создаем ФИЗИЧЕСКИЙ МИР
    zem::physics::PhysicsWorld world;

    // Создаем список хендлов, чтобы мы знали, кого рисовать.
    // (Позже движок сам сможет давать список активных тел, но пока храним сами)
    std::vector<zem::core::BodyHandle> bodies;

    // Спавним 10 шариков в ряд
    for (int i = 0; i < 10; ++i) {
        // Создаем тело в движке: (x, y, z), масса 1.0
        auto handle = world.CreateBody(1.0f, zem::math::Vector3(i * 2.0f, 5.0f, 0.0f));
        bodies.push_back(handle);
    }

    // 4. ГЛАВНЫЙ ЦИКЛ (Game Loop)
    while (!WindowShouldClose()) {
        // --- А. Логика (Physics Step) ---
        float dt = GetFrameTime(); // Время последнего кадра
        world.Step(dt); // Твой движок считает физику!

        // Управление камерой (мышкой)
        UpdateCamera(&camera, CAMERA_ORBITAL);

        // --- Б. Рендер (Рисование) ---
        BeginDrawing();
            ClearBackground(RAYWHITE); // Чистим экран белым цветом

            BeginMode3D(camera);
                // Рисуем сетку (пол), чтобы было видно пространство
                DrawGrid(20, 1.0f);

                // Рисуем наши тела
                for (const auto& handle : bodies) {
                    // 1. Запрашиваем позицию у движка (DOD)
                    zem::math::Vector3 pos = world.GetPosition(handle);

                    // 2. Конвертируем в формат Raylib для отрисовки
                    Vector3 raylibPos = { (float)pos.x, (float)pos.y, (float)pos.z };

                    // 3. Рисуем красную сферу радиусом 0.5
                    DrawSphere(raylibPos, 0.5f, RED);
                    DrawSphereWires(raylibPos, 0.5f, 16, 16, MAROON); // Обводка
                }
            EndMode3D();

            DrawText("DOD Physics Demo", 10, 10, 20, DARKGRAY);
            DrawFPS(10, 40);
        EndDrawing();
    }

    // 5. Очистка
    CloseWindow();
  return 0;
}
