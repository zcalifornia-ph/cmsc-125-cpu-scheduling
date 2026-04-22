<!-- Improved compatibility of back to top link -->
<a id="readme-top"></a>

<p align="center">
  <a href="https://github.com/zcalifornia-ph/cmsc-125-cpu-scheduling/graphs/contributors"><img src="https://img.shields.io/github/contributors/zcalifornia-ph/cmsc-125-cpu-scheduling.svg?style=for-the-badge" alt="Contributors" /></a>
  <a href="https://github.com/zcalifornia-ph/cmsc-125-cpu-scheduling/network/members"><img src="https://img.shields.io/github/forks/zcalifornia-ph/cmsc-125-cpu-scheduling.svg?style=for-the-badge" alt="Forks" /></a>
  <a href="https://github.com/zcalifornia-ph/cmsc-125-cpu-scheduling/stargazers"><img src="https://img.shields.io/github/stars/zcalifornia-ph/cmsc-125-cpu-scheduling.svg?style=for-the-badge" alt="Stargazers" /></a>
  <a href="https://github.com/zcalifornia-ph/cmsc-125-cpu-scheduling/issues"><img src="https://img.shields.io/github/issues/zcalifornia-ph/cmsc-125-cpu-scheduling.svg?style=for-the-badge" alt="Issues" /></a>
  <a href="LICENSE.txt"><img src="https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge" alt="MIT License" /></a>
  <a href="https://linkedin.com/in/zcalifornia"><img src="https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555" alt="LinkedIn" /></a>
</p>

## [![Project Screenshot][product-screenshot]][repo-url]
##

<div align="center">
  <h3 align="center">CMSC 125 - CPU Scheduling</h3>

  <p align="center">
    <strong>A comparative implementation of four CPU scheduling algorithms in C/C++ for CMSC 125.</strong>
    <br />
    Version: v0.0.7
    <br />
    Status: FCFS, SJF, RR, and Priority C implementations are completed; Unit F Bolts B-F1 and B-F2 are learner-approved; PDF assembly and zip packaging remain pending.
    <br />
    <a href="docs/version-0.0.7-docs.md"><strong>Read the latest version notes »</strong></a>
    <br />
    <br />
    <a href="LICENSE.txt">View License</a>
    &middot;
    <a href="THIRD-PARTY-NOTICES.md">Third-Party Notices</a>
    &middot;
    <a href="https://github.com/zcalifornia-ph/cmsc-125-cpu-scheduling/issues">Open Issue</a>
  </p>
</div>

## Table of Contents

1. <a href="#about-the-project">About The Project</a>
   - <a href="#what-this-repository-is">What This Repository Is</a>
   - <a href="#what-this-repository-is-not-yet">What This Repository Is Not Yet</a>
   - <a href="#built-with">Built With</a>
2. <a href="#assignment-scope">Assignment Scope</a>
   - <a href="#required-algorithms">Required Algorithms</a>
   - <a href="#expected-deliverables">Expected Deliverables</a>
3. <a href="#repository-layout">Repository Layout</a>
4. <a href="#getting-started">Getting Started</a>
   - <a href="#prerequisites">Prerequisites</a>
   - <a href="#quick-start">Quick Start</a>
5. <a href="#reference-materials">Reference Materials</a>
   - <a href="#local-formatted-reference-articles">Local Formatted Reference Articles</a>
   - <a href="#original-external-study-links">Original External Study Links</a>
6. <a href="#current-status">Current Status</a>
7. <a href="#submission-checklist">Submission Checklist</a>
8. <a href="#contributing">Contributing</a>
9. <a href="#license">License</a>
10. <a href="#third-party-notices">Third-Party Notices</a>
11. <a href="#contact">Contact</a>

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## About The Project

This repository is a public academic project for CMSC 125 focused on implementing and comparing classic CPU scheduling algorithms in C or C++.

The work is intended to document both the implementation side of the assignment and the repository-side project hygiene around versioning, licensing, contribution rules, and third-party notices.

### What This Repository Is

* A structured repository for an individual CMSC 125 CPU scheduling assignment.
* A place to track the required FCFS, SJF, Priority, and Round Robin implementations.
* A repository that separates repository-owned material under `LICENSE.txt` from third-party notices under `THIRD-PARTY-NOTICES.md`.

### What This Repository Is Not Yet

* Not yet a complete submission repository with the final `california_rfm.pdf` tracked.
* Not yet a finished packaging repository with the final `california.zip` tracked.
* Not a general-purpose operating systems library or benchmarking suite.

### Built With

* [![C][c-shield]][c-url]
* [![C++][cpp-shield]][cpp-url]
* [![Markdown][markdown-shield]][markdown-url]
* [![MIT License][license-inline-shield]][license-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Assignment Scope

This repository supports an individual assignment whose objective is to implement different CPU scheduling algorithms on a custom set of processes using C/C++, then compare their scheduling metrics.

### Required Algorithms

* First Come First Serve (FCFS)
* Shortest Job First (SJF)
* Priority Scheduling
* Round Robin (RR)

Rules reflected in the repository documentation:

* FCFS, SJF, and RR should use the same input dataset so the comparison is fair.
* Priority Scheduling may use the same dataset or a different one with explicit priority values added.
* Each algorithm should live in its own C or C++ source file.

### Expected Deliverables

The assignment expects:

1. Four source files, one per scheduling algorithm.
2. One PDF containing labeled screenshots and the written comparison of average waiting time, average response time, and average turnaround time.
3. One ZIP archive containing the four source files and the PDF.

If the required filename pattern follows the maintainer surname used in this repository, the expected output names would be:

* `california_fcfs.c` or `california_fcfs.cpp`
* `california_sjf.c` or `california_sjf.cpp`
* `california_prio.c` or `california_prio.cpp`
* `california_rr.c` or `california_rr.cpp`
* `california_rfm.pdf`

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Repository Layout

```text
cmsc-125-cpu-scheduling/
  README.md
  CHANGELOG.md
  LICENSE.txt
  THIRD-PARTY-NOTICES.md
  CODE_OF_CONDUCT.md
  CONTRIBUTING.md
  SECURITY.md

  docs/
    articles/
      cpu-scheduling.md
      first-come-first-serve.md
      priority-scheduling.md
      round-robin.md
      shortest-job-first.md
    version-0.0.1-docs.md
    version-0.0.2-docs.md
    version-0.0.3-docs.md
    version-0.0.4-docs.md
    version-0.0.5-docs.md
    version-0.0.6-docs.md
    version-0.0.7-docs.md

  repo/
    images/
      project_screen.png

  cmsc-125-cpu-scheduling/
    REQUIREMENTS.md
    california_fcfs.c
    california_sjf.c
    california_rr.c
    california_prio.c
    artifacts/
      screenshots/
        01_fcfs.png
        02_sjf.png
        03_rr.png
        04_prio.png
      writeup.md
    ai-dlc-docs/
      requirements/
        INCEPTION.md
      design-artifacts/
      traceability/
      test-artifacts/
```

Current tracked emphasis:

* root documentation and repository policy files are present
* the license baseline is established in `LICENSE.txt`
* repository-owned material and third-party notice material are described separately
* local formatted reference articles now exist under `docs/articles/`
* algorithm implementations for FCFS, SJF, RR, and Priority are now present in `cmsc-125-cpu-scheduling/`
* AI-DLC construction artifacts for Units `U-A` through `U-F` are now persisted under `cmsc-125-cpu-scheduling/ai-dlc-docs/`
* Unit F Bolt `B-F1` screenshot artifacts now exist under `cmsc-125-cpu-scheduling/artifacts/screenshots/`
* Unit F Bolt `B-F2` comparative write-up now exists at `cmsc-125-cpu-scheduling/artifacts/writeup.md`
* Unit F Bolt `B-F3` PDF assembly and Unit G packaging (`california_rfm.pdf`, `california.zip`) are still pending

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Getting Started

### Prerequisites

You need one working C or C++ compiler, such as:

* GCC via MinGW-w64
* Clang
* Microsoft Visual C++ Build Tools

### Quick Start

1. Clone the repository.
   ```sh
   git clone https://github.com/zcalifornia-ph/cmsc-125-cpu-scheduling.git
   cd cmsc-125-cpu-scheduling
   ```
2. Enter the project target directory where implementation files live.
   ```sh
   cd cmsc-125-cpu-scheduling
   ```
3. Compile each `.c` implementation with strict warnings enabled.
4. Run each program and confirm outputs against `ai-dlc-docs/requirements/INCEPTION.md` section 6.
5. Capture labeled screenshots for the report and assemble `california_rfm.pdf`.
6. Package the final deliverables into `california.zip` once Unit F and Unit G are complete.

Example compile and run commands on Windows PowerShell:

Using GCC for a C source file:

```powershell
gcc -std=c99 -Wall -Wextra .\california_fcfs.c -o .\california_fcfs.exe
.\california_fcfs.exe
```

Using G++ for a C++ source file:

```powershell
g++ -Wall -Wextra .\california_fcfs.cpp -o .\california_fcfs.exe
.\california_fcfs.exe
```

Repeat the same pattern for `sjf`, `prio`, and `rr`.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Reference Materials

### Local Formatted Reference Articles

The repository now includes locally formatted Markdown versions of the study material under `docs/articles/`:

* [`docs/articles/cpu-scheduling.md`](docs/articles/cpu-scheduling.md)
* [`docs/articles/first-come-first-serve.md`](docs/articles/first-come-first-serve.md)
* [`docs/articles/priority-scheduling.md`](docs/articles/priority-scheduling.md)
* [`docs/articles/round-robin.md`](docs/articles/round-robin.md)
* [`docs/articles/shortest-job-first.md`](docs/articles/shortest-job-first.md)

### Original External Study Links

The assignment brief points to the following study materials:

* CPU Scheduling overview: <https://www.studytonight.com/operating-system/cpu-scheduling>
* FCFS: <https://www.studytonight.com/operating-system/first-come-first-serve>
* SJF: <https://www.studytonight.com/operating-system/shortest-job-first>
* Priority Scheduling: <https://www.studytonight.com/operating-system/priority-scheduling>
* Round Robin: <https://www.studytonight.com/operating-system/round-robin-scheduling>

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Current Status

* Version: `0.0.7`
* Repository description: A comparative implementation of four scheduling algorithms in C for CMSC 125.
* Current state: governance docs, license baseline, third-party notices, local reference articles, four C algorithm implementations (FCFS/SJF/RR/Priority), Unit F Bolt `B-F1` screenshots, and Unit F Bolt `B-F2` comparative write-up are in place.
* Current gap: Unit F Bolt `B-F3` PDF assembly and Unit G packaging (`california.zip`) are still pending.

Supporting documentation already present:

* `docs/version-0.0.1-docs.md` for the repository bootstrap record
* `docs/version-0.0.2-docs.md` for the MIT license selection and notice-alignment record
* `docs/version-0.0.3-docs.md` for the README presentation refresh and template-alignment record
* `docs/version-0.0.4-docs.md` for the local reference-article formatting and notice-alignment record
* `docs/version-0.0.5-docs.md` for the Unit B/C/D/E build completion and AI-DLC artifact/validation record
* `docs/version-0.0.6-docs.md` for the Unit F Bolt B-F1 screenshot completion and learner-approval record
* `docs/version-0.0.7-docs.md` for the Unit F Bolt B-F2 write-up completion and learner-approval record

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Submission Checklist

* One source file exists for each required algorithm.
* FCFS, SJF, and RR use the same test data.
* Priority Scheduling includes valid priority input.
* Program runs are captured with labeled screenshots.
* The PDF includes both screenshots and the written comparison.
* The ZIP archive contains the four source files and the PDF only.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Contributing

This repository primarily serves as an individual academic project, so external contribution is secondary to assignment completion.

If changes are proposed, read the following first:

* `CONTRIBUTING.md`
* `CODE_OF_CONDUCT.md`
* `SECURITY.md`

Contributions should preserve:

* assignment correctness
* metric reproducibility
* academic integrity
* repository-owned licensing and third-party notice boundaries

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## License

Repository-owned material in this repository is distributed under the MIT License.
See `LICENSE.txt` for the full license text.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Third-Party Notices

Third-party license texts, notices, and reference materials are documented separately in `THIRD-PARTY-NOTICES.md`.

That file matters because:

* it clarifies that bundled third-party notices do not override the repository license
* it distinguishes repository-owned material from retained reference or notice material
* it provides the right place to document third-party obligations if external code or assets are later added

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Contact

Maintainer - [@zcalifornia_](https://twitter.com/zcalifornia_) - zecalifornia@up.edu.ph

Project Link: [https://github.com/zcalifornia-ph/cmsc-125-cpu-scheduling](https://github.com/zcalifornia-ph/cmsc-125-cpu-scheduling)

LinkedIn: [https://www.linkedin.com/in/zcalifornia/](https://www.linkedin.com/in/zcalifornia/)

ORCID: [https://orcid.org/0009-0002-2357-7606](https://orcid.org/0009-0002-2357-7606)

ResearchGate: [https://www.researchgate.net/profile/Zildjian-California](https://www.researchgate.net/profile/Zildjian-California)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
[contributors-shield]: https://img.shields.io/github/contributors/zcalifornia-ph/cmsc-125-cpu-scheduling.svg?style=for-the-badge
[contributors-url]: https://github.com/zcalifornia-ph/cmsc-125-cpu-scheduling/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/zcalifornia-ph/cmsc-125-cpu-scheduling.svg?style=for-the-badge
[forks-url]: https://github.com/zcalifornia-ph/cmsc-125-cpu-scheduling/network/members
[stars-shield]: https://img.shields.io/github/stars/zcalifornia-ph/cmsc-125-cpu-scheduling.svg?style=for-the-badge
[stars-url]: https://github.com/zcalifornia-ph/cmsc-125-cpu-scheduling/stargazers
[issues-shield]: https://img.shields.io/github/issues/zcalifornia-ph/cmsc-125-cpu-scheduling.svg?style=for-the-badge
[issues-url]: https://github.com/zcalifornia-ph/cmsc-125-cpu-scheduling/issues
[license-shield]: https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge
[license-url]: LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/zcalifornia
[product-screenshot]: repo/images/project_screen.png
[repo-url]: https://github.com/zcalifornia-ph/cmsc-125-cpu-scheduling
[c-shield]: https://img.shields.io/badge/C-Programming-A8B9CC?style=for-the-badge&logo=c&logoColor=white
[c-url]: https://en.wikipedia.org/wiki/C_(programming_language)
[cpp-shield]: https://img.shields.io/badge/C%2B%2B-Programming-00599C?style=for-the-badge&logo=cplusplus&logoColor=white
[cpp-url]: https://isocpp.org/
[markdown-shield]: https://img.shields.io/badge/Markdown-Docs-000000?style=for-the-badge&logo=markdown&logoColor=white
[markdown-url]: https://www.markdownguide.org/
[license-inline-shield]: https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge
