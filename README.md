# PCA Image Compression

이미지를 행렬로 바라보고, PCA(주성분 분석)를 이용해 압축·복원하는 과정을 **선형대수 개념 하나하나를 직접 구현하며** 학습하는 프로젝트입니다.

```
이미지 선택 → PCA 압축 → 복원 → 원본과 비교 → 압축률 / PSNR / MSE / 실행시간
```

## 목표

OpenCV의 행렬 연산에 기대지 않고, `Matrix` 클래스를 직접 만들어 평균 계산 → Centering → 공분산 행렬 → 고유값/고유벡터 → 차원 축소 → 투영 → 복원까지 이어지는 PCA의 전 과정을 선형대수 개념과 함께 단계별로 구현합니다.

## 기술 스택

- **C++**
- **CMake** – 빌드 시스템
- **OpenCV** – 이미지 입출력 전용 (연산에는 사용하지 않음)
- **Eigen** – Eigenvalue / Eigenvector 계산

## 프로젝트 구조

```
PCAImageCompression/
├── src/
├── include/
├── images/
├── output/
└── CMakeLists.txt
```

## 개발 단계 (Stages)

각 단계는 이전 단계의 결과물 위에서 진행되며, 완료 후 다음 단계로 넘어갑니다.

| Stage | 이름 | 목표 | 다루는 선형대수 개념 |
|---|---|---|---|
| 0 | 환경 구축 | CMake / OpenCV / Eigen 설치, 프로젝트 구조 생성 | - |
| 1 | 이미지를 행렬로 | 이미지를 `Image`가 아닌 `Matrix`로 바라보기 | Matrix |
| 2 | 행렬 클래스 만들기 | 생성/출력/전치/행렬곱/덧셈/뺄셈을 갖춘 `Matrix` 클래스 직접 구현 | Matrix, Matrix Multiplication, Transpose |
| 3 | 이미지 → Matrix 변환 | OpenCV는 이미지 입력용으로만 사용, 이후 전부 `MyMatrix`로 전환 | - |
| 4 | 평균 계산 | 전체 픽셀 평균 계산 | 벡터/행렬 평균 |
| 5 | Centering | 평균을 빼서 데이터를 원점 중심으로 이동 | 벡터, 평행이동 |
| 6 | 공분산 행렬 | Centered Matrix로부터 공분산 행렬 생성 | 행렬곱, 전치, 분산, 공분산 |
| 7 | Eigenvalue / Eigenvector | Eigen 라이브러리로 고유값·고유벡터 계산 (직접 구현 X) | Eigenvalue, Eigenvector, Diagonalization |
| 8 | Principal Component 선택 | 고유값 정렬 후 상위 k개 선택 | 차원 축소, Basis, Span |
| 9 | Projection | 새로운 Basis로 데이터 투영 | Basis, Span, Matrix Multiplication |
| 10 | Reconstruction | 압축된 데이터를 원래 공간으로 역투영 복원 | Basis, Projection |
| 11 | 평가 | MSE, PSNR, 압축률 계산 | (영상처리) |
| 12 | UI | 원본 → 압축 → 복원 → 비교 흐름 완성 | - |

### ⭐ 추가 챌린지 (전체 완료 후)

PCA가 실제로 데이터를 회전시키고 새로운 기저로 표현하는 과정을 시각화합니다.

- 2차원 점 데이터 생성
- 원본 데이터 산점도
- 평균 제거 후 데이터
- 주성분(고유벡터) 표시
- 새로운 좌표계로 투영된 결과

를 순서대로 보여주는 시각화 프로그램 제작.

## 진행 상황

- [x] Stage 0 — 환경 구축
- [ ] Stage 1 — 이미지를 행렬로 바라보기
- [ ] Stage 2 — 행렬 클래스 만들기
- [ ] Stage 3 — 이미지를 Matrix 클래스로 변환
- [ ] Stage 4 — 평균 계산
- [ ] Stage 5 — Centering
- [ ] Stage 6 — 공분산 행렬
- [ ] Stage 7 — Eigenvalue / Eigenvector
- [ ] Stage 8 — Principal Component 선택
- [ ] Stage 9 — Projection
- [ ] Stage 10 — Reconstruction
- [ ] Stage 11 — 평가 (MSE / PSNR / 압축률)
- [ ] Stage 12 — UI
- [ ] ⭐ PCA 시각화 챌린지

## 빌드 방법

```bash
mkdir build && cd build
cmake ..
make
```

## 라이선스

MIT
