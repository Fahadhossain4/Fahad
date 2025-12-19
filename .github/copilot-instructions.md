## Purpose

Short, actionable instructions to help AI coding agents be productive in this small mixed-language workspace.

## Repo snapshot / big picture

- Root contains a mix of single-file examples and small programs: `index.js`, `code1.c`, `code2.c`, `code3.c`, and a few files/directories like `code1`, `code2`, `code3`.
- There is no package.json, no CI config, and no test harness. Treat this repository as a set of independent example programs rather than a single monolithic app.

## What to edit and why

- Primary JS entry: `index.js`. It's a small runnable script used for quick demos. Example: currently there is a typo `cinsole.log(...)` which causes a runtime ReferenceError — change to `console.log(...)`.
- C examples: `code1.c`, `code2.c`, `code3.c` are independent C programs. Edit them only when fixing obvious bugs or adding small features; compile locally after changes.

## How to run and validate changes (no hidden scripts)

- Run Node example:

  node index.js

  Expect to see several console lines; a `ReferenceError` will appear if `cinsole.log` remains.

- Compile and run C examples (one at a time):

  gcc -Wall -Wextra -o code1 code1.c && ./code1

  Replace `code1`/`code1.c` with the specific file name.

## Project-specific patterns and conventions

- Small, single-file programs. Prefer minimal, targeted changes. Avoid introducing new dependencies (no package.json present).
- Keep console output formatting consistent with the existing simple style (multiple `console.log` lines). When modifying `index.js`, maintain the script-level, top-down structure.
- When editing C files, preserve simple procedural style (no large refactors). Compile with `-Wall -Wextra` to catch warnings.

## Integration points and external dependencies

- There are no external package manifests. Changes should not assume package managers or CI unless the maintainer requests adding them.

## Example safe edits (explicit)

- Fix the `index.js` typo:

  - Problem: `cinsole.log('Total age is: ' + (age1 + age2));`
  - Fix: change to `console.log('Total age is: ' + (age1 + age2));`

- If adding a new script or test harness, include a short README and avoid changing unrelated files.

## Pull request & commit guidance for AI-generated changes

- Keep PRs small and focused: one logical change per PR (fix, small feature, or add example).
- Commit message style: short imperative prefix, e.g. `fix: correct console typo in index.js` or `feat: add simple runner for code2.c`.

## What I looked for (and didn't find)

- No `.github/copilot-instructions.md`, `AGENT.md`, or README.md existed when these instructions were created. If you have organizational conventions, add them to the top of this file.

---
If any of these assumptions are incorrect or you want a different scope (for example, convert the workspace into a Node project with package.json, ESLint, or CI), say so and I will update the file and add necessary scripts.
