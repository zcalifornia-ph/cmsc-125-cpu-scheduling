# Security Policy

## Scope

This repository is a small academic C/C++ project rather than a deployed production service, but security and correctness still matter.
Relevant security concerns include:

- unsafe input handling
- crashes caused by malformed or unexpected data
- memory-safety issues
- undefined behavior
- malicious or misleading packaged artifacts

## Supported Versions

| Version | Supported |
| --- | --- |
| 1.0.x | Yes |
| 0.x | No |

## Reporting a Vulnerability

Do not open a public issue for a suspected vulnerability.
Report it privately to <zecalifornia@up.edu.ph>.

Include:

- affected file or component
- steps to reproduce
- expected behavior
- actual behavior
- impact assessment
- any suggested fix, if available

## Response Expectations

This repository is maintained on a best-effort basis.
Good-faith reports will be acknowledged and reviewed as time permits, with priority given to issues that could mislead users, corrupt outputs, or expose unsafe behavior.

## Safe Disclosure Guidelines

- Do not exploit a vulnerability beyond what is needed to demonstrate it.
- Do not access, alter, or destroy data that is not yours.
- Avoid public disclosure until the maintainer has had a reasonable chance to review the issue.
